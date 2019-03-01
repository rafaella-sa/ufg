package eventos.persistencia.impl;

import eventos.model.Cliente;
import eventos.model.Endereco;
import eventos.persistencia.base.CSVToFile;
import java.util.ArrayList;
import java.util.List;

public class ClienteGravacaoHelper implements ServiceHelper<Cliente>{

    private final String ARQUIVO = "clientes.csv";
    private final CSVToFile gerenciadorDeArquivo;
    
    public ClienteGravacaoHelper(){
       gerenciadorDeArquivo = new CSVToFile(ARQUIVO);
    }
    
    @Override
    public boolean gravarObjeto(Cliente cliente) {
        if(!gerenciadorDeArquivo.contem(cliente.getCpf())){
            return gerenciadorDeArquivo.gravarLinha(toLine(cliente));
        }else{
            return false;
        }
    }

    @Override
    public void gravarObjetos(List<Cliente> clientes) {
       for(Cliente comprador : clientes){
           this.gravarObjeto(comprador);
       }
    }
    
    @Override
    public Cliente getObjetoPorId(int cpf, int posicao) {
        String linha = gerenciadorDeArquivo.getLinhaPorId(cpf, posicao);
        if(linha != null){
            Cliente resultado = getObject(linha);
            return resultado;
        }else{
            return null;
        }
        
    }

    @Override
    public List<Cliente> getTodosObjetos() {
        List<String> listaObjetos = gerenciadorDeArquivo.getLinhas();
        List<Cliente> resultado = new ArrayList<Cliente>();
        for(String entrada : listaObjetos){
            Cliente cliente = getObject(entrada);
            resultado.add(cliente);
        }
        return resultado;
    }
    
    private String toLine(Cliente c){
        StringBuilder sb = new StringBuilder();
        sb.append(c.getCpf());
        sb.append(ServiceHelper.SEPARADOR);
        sb.append(c.getNome());
        sb.append(ServiceHelper.SEPARADOR);
        sb.append(c.getEndereco().getRua());
        sb.append(ServiceHelper.SEPARADOR);
        sb.append(c.getEndereco().getNumero());
        sb.append(ServiceHelper.SEPARADOR);
        sb.append(c.getEndereco().getComplemento());
        sb.append(ServiceHelper.SEPARADOR);
        sb.append(c.getEndereco().getBairro());
        sb.append(ServiceHelper.SEPARADOR);
        sb.append(c.getEndereco().getCep());
        sb.append(ServiceHelper.SEPARADOR);
        sb.append(c.getTelefone());
        return sb.toString();
    }
    
    private Cliente getObject(String line){
        String[] cliente = line.split(
                String.valueOf(ServiceHelper.SEPARADOR));
        int cpf = Integer.parseInt(cliente[0]);
        String nome = cliente[1];
        String rua = cliente[2];
        int numero = Integer.parseInt(cliente[3]);
        String complemento = cliente[4];
        String bairro = cliente[5];
        int cep = Integer.parseInt(cliente[6]);
        Endereco e = new Endereco(rua, numero, complemento, bairro, cep);
        String telefone = cliente[7];
        Cliente resultado = new Cliente(cpf, nome, e, telefone);
        return resultado;
    }

    @Override
    public boolean remove(Cliente cliente) {
        return gerenciadorDeArquivo.removerLinha(cliente.getCpf());
    }
    
    @Override
    public boolean imprimeObjetos(){
        List<Cliente> clientesGuardados = this.getTodosObjetos();
        if(clientesGuardados.isEmpty()){
            System.out.println("Nao ha clientes cadastrados no sistema. ");
            return false;
                    }
        else{
            for(Cliente cliente : clientesGuardados){
                cliente.imprimirCliente();
        }
            return true;
        }
    }
}


