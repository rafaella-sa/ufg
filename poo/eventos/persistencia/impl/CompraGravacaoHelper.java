package eventos.persistencia.impl;

import eventos.model.Compra;
import eventos.model.Pagamento;
import java.util.Calendar;
import eventos.persistencia.base.CSVToFile;
import java.util.ArrayList;
import java.util.List;

public class CompraGravacaoHelper implements ServiceHelper<Compra>{
    private final String ARQUIVO = "compras.csv";
    private final CSVToFile gerenciadorDeArquivo;
    
    public CompraGravacaoHelper(){
       gerenciadorDeArquivo = new CSVToFile(ARQUIVO);
    }
    
    @Override
    public boolean gravarObjeto(Compra compra) {
        if(!gerenciadorDeArquivo.contem(compra.getId_ingresso())){
            return gerenciadorDeArquivo.gravarLinha(toLine(compra));
        }else{
            return false;
        }
    }

    @Override
    public void gravarObjetos(List<Compra> compras) {
       for(Compra compra : compras){
           this.gravarObjeto(compra);
       }
    }
    
    @Override
    public Compra getObjetoPorId(int id, int posicao) {
        String linha = gerenciadorDeArquivo.getLinhaPorId(id, posicao);
        if(linha != null){
            Compra resultado = getObject(linha);
            return resultado;
        }else{
            return null;
        }
        
    }
   
    @Override
    public List<Compra> getTodosObjetos() {
        List<String> listaObjetos = gerenciadorDeArquivo.getLinhas();
        List<Compra> resultado = new ArrayList<Compra>();
        for(String entrada : listaObjetos){
            Compra compra = getObject(entrada);
            resultado.add(compra);
        }
        return resultado;
    }
     
    private String toLine(Compra c){
        StringBuilder sb = new StringBuilder();
        sb.append(c.getId_ingresso());
        sb.append(ServiceHelper.SEPARADOR);
        sb.append(c.getId_evento());
        sb.append(ServiceHelper.SEPARADOR);
        sb.append(c.getCpf_cliente());
        sb.append(ServiceHelper.SEPARADOR);       
        sb.append(c.getNomecliente());
        sb.append(ServiceHelper.SEPARADOR);
        sb.append(c.getData().get(Calendar.DAY_OF_MONTH));
        sb.append(ServiceHelper.SEPARADOR);
        sb.append(c.getData().get(Calendar.MONTH));
        sb.append(ServiceHelper.SEPARADOR);
        sb.append(c.getData().get(Calendar.YEAR));
        sb.append(ServiceHelper.SEPARADOR);
        sb.append(c.getPagamento());
        sb.append(ServiceHelper.SEPARADOR);
        sb.append(c.getValor());
        return sb.toString();
    }
    
    private Compra getObject(String line){
        String[] compra = line.split(
                String.valueOf(ServiceHelper.SEPARADOR));
        int id_ingresso = Integer.parseInt(compra[0]);
        int id_evento = Integer.parseInt(compra[1]);
        int cpf_cliente = Integer.parseInt(compra[2]);
        String nomecliente = compra[3];
        Calendar data = Calendar.getInstance();
        data.set(Calendar.DAY_OF_MONTH, Integer.parseInt(compra[4]));
        data.set(Calendar.MONTH, Integer.parseInt(compra[5]));
        data.set(Calendar.YEAR, Integer.parseInt(compra[6]));       
        Pagamento pagamento = Pagamento.valueOf(compra[7]);
        float valor = Float.parseFloat(compra[8]);
        Compra resultado = new Compra(id_ingresso, id_evento, cpf_cliente, nomecliente, data,
        pagamento, valor);
        return resultado;
    }

    @Override
    public boolean remove(Compra compra) {
        return gerenciadorDeArquivo.removerLinha(compra.getId_ingresso());
    }
    
    @Override
    public boolean imprimeObjetos(){
        List<Compra> comprasGuardadas = this.getTodosObjetos();
        if(comprasGuardadas.isEmpty()){
            System.out.println("Nao ha compras cadastradas no sistema. ");
            return false;
        }
        else{
            for(Compra compra : comprasGuardadas){
                compra.imprimirCompra();
            }
            return true;
        } 
    }
}
