package eventos.persistencia.impl;

import eventos.persistencia.base.CSVToFile;
import java.util.ArrayList;
import java.util.List;
import eventos.model.Evento;
import java.util.Calendar;

public class EventoGravacaoHelper implements ServiceHelper<Evento>{
    private final String ARQUIVO = "eventos.csv";
    private final CSVToFile gerenciadorDeArquivo;
    
    public EventoGravacaoHelper(){
       gerenciadorDeArquivo = new CSVToFile(ARQUIVO);
    }
    
    @Override
    public boolean gravarObjeto(Evento evento) {
        if(!gerenciadorDeArquivo.contem(evento.getId())){
            return gerenciadorDeArquivo.gravarLinha(toLine(evento));
        }else{
            return false;
        }
    }

    @Override
    public void gravarObjetos(List<Evento> eventos) {
       for(Evento evento: eventos){
           this.gravarObjeto(evento);
       }
    }
    
    @Override
    public Evento getObjetoPorId(int id, int posicao) {
        String linha = gerenciadorDeArquivo.getLinhaPorId(id, posicao);
        if(linha != null){
            Evento resultado = getObject(linha);
            return resultado;
        }else{
            return null;
        }
        
    }

    @Override
    public List<Evento> getTodosObjetos() {
        List<String> listaObjetos = gerenciadorDeArquivo.getLinhas();
        List<Evento> resultado = new ArrayList<Evento>();
        for(String entrada : listaObjetos){
            Evento evento = getObject(entrada);
            resultado.add(evento);
        }
        return resultado;
    }
       
    private String toLine(Evento evento){
        StringBuilder sb = new StringBuilder();
        sb.append(evento.getId());
        sb.append(ServiceHelper.SEPARADOR);
        sb.append(evento.getNome());
        sb.append(ServiceHelper.SEPARADOR);
        sb.append(evento.getDescricao());
        sb.append(ServiceHelper.SEPARADOR);
        sb.append(evento.getData().get(Calendar.DAY_OF_MONTH));
        sb.append(ServiceHelper.SEPARADOR);
        sb.append(evento.getData().get(Calendar.MONTH));
        sb.append(ServiceHelper.SEPARADOR);
        sb.append(evento.getData().get(Calendar.YEAR));
        sb.append(ServiceHelper.SEPARADOR);
        sb.append(evento.getLocal());
        sb.append(ServiceHelper.SEPARADOR);
        sb.append(evento.getArrecadacao());
        sb.append(ServiceHelper.SEPARADOR);
        sb.append(evento.getVendas());
        return sb.toString();
    }
    
    private Evento getObject(String line){
        String[] evento = line.split(String.valueOf(ServiceHelper.SEPARADOR));
        int id = Integer.parseInt(evento[0]);
        String nome = evento[1];
        String descricao = evento[2];
        Calendar data = Calendar.getInstance();
        data.set(Calendar.DAY_OF_MONTH, Integer.parseInt(evento[3]));
        data.set(Calendar.MONTH, Integer.parseInt(evento[4]));
        data.set(Calendar.YEAR, Integer.parseInt(evento[5]));
        String local = evento[6];
        float arrecadacao = Float.parseFloat(evento[7]);
        int vendas = Integer.parseInt(evento[8]);
        Evento resultado = new Evento(id,nome, descricao, data, local, arrecadacao, vendas);
        return resultado;
    }

    @Override
    public boolean remove(Evento evento) {
        return gerenciadorDeArquivo.removerLinha(evento.getId());
    }
    
    @Override
    public boolean imprimeObjetos() {
        List<Evento> eventosGuardados = this.getTodosObjetos();
        if(eventosGuardados.isEmpty()){
            System.out.println("Nao há eventos cadastrados no sistema.");
            return false;
        }
        else{
            for(Evento evento : eventosGuardados){
                evento.imprimirEvento();
            }
            return true;
        }
    }
    
}


