package eventos.persistencia.impl;

import eventos.model.Ingresso;
import eventos.model.Secao;
import eventos.persistencia.base.CSVToFile;
import java.util.ArrayList;
import java.util.List;

public class IngressoGravacaoHelper implements ServiceHelper<Ingresso>{

    private final String ARQUIVO = "ingressos.csv";
    private final CSVToFile gerenciadorDeArquivo;
    
    public IngressoGravacaoHelper(){
       gerenciadorDeArquivo = new CSVToFile(ARQUIVO);
    }
    
    @Override
    public boolean gravarObjeto(Ingresso ingresso) {
        if(!gerenciadorDeArquivo.contem(ingresso.getId())){
            return gerenciadorDeArquivo.gravarLinha(toLine(ingresso));
        }else{
            return false;
        }
    }

    @Override
    public void gravarObjetos(List<Ingresso> ingressos) {
       for(Ingresso ticket : ingressos){
           this.gravarObjeto(ticket);
       }
    }
    
    public void atualizarObjeto(Ingresso ingresso){
        gerenciadorDeArquivo.setLinhaPorId(ingresso.getId(), 0, toLine(ingresso));
    }
            
    @Override
    public Ingresso getObjetoPorId(int id, int posicao) {
        String linha = gerenciadorDeArquivo.getLinhaPorId(id, posicao);
        if(linha != null){
            Ingresso resultado = getObject(linha);
            return resultado;
        }else{
            return null;
        }
        
    }

    @Override
    public List<Ingresso> getTodosObjetos() {
        List<String> listaObjetos = gerenciadorDeArquivo.getLinhas();
        List<Ingresso> resultado = new ArrayList<Ingresso>();
        for(String entrada : listaObjetos){
            Ingresso ingresso = getObject(entrada);
            resultado.add(ingresso);
        }
        return resultado;
    }
     
    private String toLine(Ingresso i){
        StringBuilder sb = new StringBuilder();
        sb.append(i.getId());
        sb.append(ServiceHelper.SEPARADOR);
        sb.append(i.getCadeira());
        sb.append(ServiceHelper.SEPARADOR);
        sb.append(i.getSecao());
        sb.append(ServiceHelper.SEPARADOR);
        sb.append(i.getId_evento()); 
        sb.append(ServiceHelper.SEPARADOR);
        sb.append(i.isDisponivel());
        return sb.toString();
    }
    
    private Ingresso getObject(String line){
        String[] ingresso = line.split(
                String.valueOf(ServiceHelper.SEPARADOR));
        int id = Integer.parseInt(ingresso[0]);
        int cadeira = Integer.parseInt(ingresso[1]);
        Secao secao = Secao.valueOf(ingresso[2]);
        int id_evento = Integer.parseInt(ingresso[3]);
        boolean disponivel = Boolean.parseBoolean(ingresso[4]);   
        Ingresso resultado = new Ingresso(id, cadeira, secao, id_evento, disponivel);
        return resultado;
    }

    @Override
    public boolean remove(Ingresso ingresso) {
        return gerenciadorDeArquivo.removerLinha(ingresso.getId());
    }
    
    @Override
    public boolean imprimeObjetos(){
        List<Ingresso> ingressosGuardados = this.getTodosObjetos();
        if(ingressosGuardados.isEmpty()){
            System.out.println("Nao ha ingressos cadastrados no sistema.");
            return false;
        }
        else{
            for(Ingresso ticket : ingressosGuardados){
                ticket.imprimirIngresso();
        }
            return true;
        }
    }
}

