package eventos.view;

import eventos.model.*;
import eventos.persistencia.impl.*;
import eventos.comum.*;
import java.security.InvalidParameterException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;

public class PrincipalEventos {
    public static void main(String[] args) throws ParseException{
        //variavel para escolher opcao do menu principal
        int opcao1;
        //criacao do menu principal
        Menu menu = new Menu();
        menu.agregarItem("Gestao de eventos");
        menu.agregarItem("Gestao de clientes");
        menu.agregarItem("Gestao de ingressos/vendas");
        //criacao do submenu de eventos
        Menu submenu1 = new Menu();
        submenu1.agregarItem("Criar evento");
        submenu1.agregarItem("Listar eventos");
        submenu1.agregarItem("Cancelar evento");
        //criacao do submenu de clientes
        Menu submenu2 = new Menu();
        submenu2.agregarItem("Cadastrar cliente");
        submenu2.agregarItem("Descadastrar cliente");
        submenu2.agregarItem("Listar clientes");
        //criacao do submenu de ingressos/vendas
        Menu submenu3 = new Menu();
        submenu3.agregarItem("Vender ingresso");
        submenu3.agregarItem("Desfazer venda de ingresso");
        submenu3.agregarItem("Listar ingressos");
        submenu3.agregarItem("Listar vendas");
        //criacao dos helpers
        EventoGravacaoHelper gerenciaEventos = new EventoGravacaoHelper();
        ClienteGravacaoHelper gerenciaClientes = new ClienteGravacaoHelper();
        CompraGravacaoHelper gerenciaCompras = new CompraGravacaoHelper();
        IngressoGravacaoHelper gerenciaIngressos = new IngressoGravacaoHelper();
        //execucao do menu principal
        do{
            //le a opcao ingressada
            opcao1 = menu.executarMenu();
            switch(opcao1){
                case 1: {//passa ao submenu de eventos          
                    gestionarEventos(submenu1, gerenciaEventos, gerenciaIngressos);                    
                    break;
                }
                case 2: {//passa ao submenu de clientes              
                    gestionarClientes(submenu2, gerenciaClientes, gerenciaCompras);                    
                    break;
                }
                case 3: {//passa ao submenu de ingressos/vendas
                    gestionarIngressosEVendas(submenu3, gerenciaIngressos, gerenciaCompras, gerenciaClientes, gerenciaEventos);
                    break;
                }
                default: { //caso contrario
                        if(opcao1!=0)
                            System.out.println("Opcao inválida!");
                        else
                            System.out.println("Encerrando sistema...");
                        break;
                }
            }
        }while(opcao1!=0);
        System.out.println("Sistema encerrado com sucesso!");
    }
    
    private static void gestionarEventos(Menu submenu1, EventoGravacaoHelper 
            gerenciaEventos, IngressoGravacaoHelper gerenciaIngressos) 
            throws ParseException {
        //variavel para escolher opcao do submenu
        int opcao2;
        do{
            System.out.println("*********************************************");
            System.out.println("EVENTOS");
            //le a opcao ingressada
            opcao2 = submenu1.executarMenu();
            switch(opcao2){
                case 1: { //criar evento
                    int i;
                    try{ //pede o id do evento
                        int id = Console.readInt("Ingresse o codigo do evento: ");
                        //se o id ja foi encontrado no arquivo lanca excecao
                        if(gerenciaEventos.getObjetoPorId(id, 0)!= null)
                            throw new InvalidParameterException();
                        else{ //se nao tem nenhum evento com essa id prossegue
                            //leitura de dados
                            String nome = Console.readString("NOME: ");
                            String descricao = Console.readString("DESCRICAO: ");
                            //criacao da data
                            Calendar cal = Calendar.getInstance();
                            boolean valida = false;
                            while(!valida){ //enquanto a data for invalida
                                try {   //le a data e converte pra Calendar
                                        String data = Console.readString("DATA (formato DD/MM/AAAA): "); 
                                        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy"); 
                                        cal.setTime(sdf.parse(data));
                                        valida = true;
                                        //se a data for de hoje pra tras lanca excecao
                                        if(cal.before(Calendar.getInstance())){ 
                                            throw new InvalidParameterException();
                                        }
                                }
                                //excecao de data anterior
                                catch (ParseException e) { 
                                    System.out.println("Data invalida! Anterior ao momento de cadastro.");
                                    valida = false;
                                    }
                                //excecao de formato da data
                                catch (InvalidParameterException e){
                                    System.out.println("Data invalida! Erro de formato.");
                                    valida = false;
                                }
                            }
                            String local = Console.readString("LOCAL: ");
                            //cria o evento
                            Evento evento = new Evento(id, nome, descricao, cal, local, 0.00f, 0);
                            //cria lista de ingressos do evento
                            List<Ingresso> ingressos = new ArrayList<Ingresso>();
                            System.out.println("INGRESSOS");
                            //configura cadeiras secao normal
                            int normal = Console.readInt("Cadeiras (Secao 'Normal'): ");
                            for(i = 1; i <= normal; i++){
                                Ingresso ingresso = new Ingresso(0, i, Secao.NORMAL, evento.getId(), true);
                                ingresso.setId(ingresso.calcularId());
                                ingressos.add(ingresso);
                            }
                            //configura cadeiras secao 'vip'
                            int vip = Console.readInt("Cadeiras (Secao 'VIP'): ");
                            for(i = 1; i <= vip; i++){
                                Ingresso ingresso = new Ingresso(0, i, Secao.VIP, evento.getId(), true);
                                ingresso.setId(ingresso.calcularId());
                                ingressos.add(ingresso);
                            }
                            //grava ingressos
                            gerenciaIngressos.gravarObjetos(ingressos);
                            //grava o evento
                            if(gerenciaEventos.gravarObjeto(evento))
                                System.out.println("Evento cadastrado com sucesso!");
                            else //olhar uma exception melhor para esse caso
                                System.out.println("ERRO! Evento nao cadastrado!");   
                        }
                    }//excecao id já existente
                    catch(InvalidParameterException e){
                        System.out.println("O ID ingressado já está associado a um evento no sistema.");
                    }
                    break;
                }
                case 2:{ //mostrar eventos
                   gerenciaEventos.imprimeObjetos();
                   break;
                } 
                case 3:{ //cancelar evento
                    try{ //pede o id do evento a ser cancelado
                        int id_evento = Console.readInt("ID do evento: ");
                        //busca o evento no arquivo
                        Evento evento = gerenciaEventos.getObjetoPorId(id_evento, 0);
                        //se nao existe evento lanca excecao
                        if(evento == null)
                            throw new InvalidParameterException();
                        else{ //se evento existe continua
                            //se existe arrecadacao nao pode excluir
                            if(evento.getArrecadacao() > 0)
                                System.out.println("O evento possui ingressos vendidos. Nao é possível cancelá-lo. ");
                            else{//senao exclui
                                //recupera lista de ingressos
                                List<Ingresso> ingressos = gerenciaIngressos.getTodosObjetos();
                                //exclui os ingressos associados ao evento
                                for(Ingresso ingresso : ingressos){
                                    if(ingresso.getId_evento()== id_evento)
                                        gerenciaIngressos.remove(ingresso);
                                }
                                //remove o evento
                                if(gerenciaEventos.remove(evento))
                                    System.out.println("Evento cancelado com sucesso.");
                                else
                                    System.out.println("ERRO! Evento nao cancelado.");
                                }
                            }
                        }
                    catch(InvalidParameterException e){ //se evento nao esta cadastrado
                        System.out.println("Nao há evento cadastrado com este ID no sistema.");
                    }
                    break;
                 }
                default: {
                mensagemDefault(opcao2);                                
                    break;
                }
            }
            System.out.println("*********************************************");
        }while(opcao2!=0);
    } 
    
    private static void gestionarClientes(Menu submenu2, ClienteGravacaoHelper 
            gerenciaClientes, CompraGravacaoHelper gerenciaCompras) {
        int opcao2;
        //gestao de clientes
        do{
            System.out.println("*********************************************");
            System.out.println("CLIENTES");
            System.out.println("*********************************************");
            opcao2 = submenu2.executarMenu();
            switch(opcao2){
                case 1: { //cadastrar cliente
                    try{
                        int cpf = Console.readInt("CPF: ");
                        if(cpf<=0 || gerenciaClientes.getObjetoPorId(cpf, 0)!=null)
                            throw new InvalidParameterException();
                        else{
                            Cliente c;
                            Endereco e;
                            String nome = Console.readString("NOME: ");
                            System.out.println("ENDEREÇO");
                            String rua = Console.readString("Rua/Avenida: ");
                            int numero = Console.readInt("Número: ");
                            String complemento = Console.readString("COMPLEMENTO: "); 
                            String bairro = Console.readString("BAIRRO: "); 
                            int cep = Console.readInt("CEP: ");
                            String telefone = Console.readString("TELEFONE: "); 
                            e = new Endereco(rua, numero, complemento, bairro, cep);
                            c = new Cliente(cpf, nome, e, telefone);
                            //se foi possivel gravar no arquivo retorna verdadeiro
                            if(gerenciaClientes.gravarObjeto(c))
                                System.out.println("Cadastro realizado com sucesso!");
                            else //senao retorna falso
                                System.out.println("ERRO! Cadastro nao realizado!");
                        }
                    }
                    catch (InvalidParameterException e){
                        System.out.println("ERRO! CPF invalido ou cliente já cadastrado!");
                    }
                    break;
                }
                case 2:{ //descadastrar cliente
                    try{
                        int cpf = Console.readInt("Ingresse o CPF: ");
                        Cliente cliente = gerenciaClientes.getObjetoPorId(cpf, 0);
                        if(cliente==null)
                            throw new InvalidParameterException();
                        else{
                            if(gerenciaCompras.getObjetoPorId(cpf, 2) == null){
                                if(gerenciaClientes.remove(cliente))
                                    System.out.println("Cliente descadastrado com sucesso.");
                                else //senao retorna falso
                                    System.out.println("ERRO! Cliente nao descadastrado.");
                            }
                            else
                                System.out.println("O cliente de CPF " + cpf + " tem um histórico de compras e nao pode ser descadastrado.");
                        }
                    }
                    catch(InvalidParameterException e){
                        System.out.println("Nao há cliente com o CPF ingressado cadastrado no banco de dados.");
                    }
                    break;
                }
                case 3: { //listar clientes
                    gerenciaClientes.imprimeObjetos();
                    break;
                }
                default: {
                    mensagemDefault(opcao2);     
                    break;
                }
            }
            
        }while(opcao2!=0);
    }
    
    private static void gestionarIngressosEVendas(Menu submenu3, 
            IngressoGravacaoHelper gerenciaIngressos, CompraGravacaoHelper 
                    gerenciaCompras, ClienteGravacaoHelper gerenciaClientes, 
                    EventoGravacaoHelper gerenciaEventos){
    int opcao2;
        //gestao de ingressos/vendas
        do{
            System.out.println("*********************************************");
            System.out.println("INGRESSOS/VENDAS");
            System.out.println("*********************************************");
            opcao2 = submenu3.executarMenu();
            switch(opcao2){
                case 1: { //vender ingresso
                    try{ //se nao tem eventos cadastrados lanca excecao
                        if(!gerenciaEventos.imprimeObjetos())
                            throw new IllegalArgumentException();
                        else{//se tem evento no sistema
                            //mostra os ingressos
                            System.out.println("Ingressos: ");
                            gerenciaIngressos.imprimeObjetos();
                            //pede o cpf do cliente
                            int cpf = Console.readInt("CPF: ");
                            //busca o cliente no sistema pelo cpf
                            Cliente cliente = gerenciaClientes.getObjetoPorId(cpf, 0);
                            //se cliente nao existe lanca excecao
                            if(cliente == null)
                                throw new InvalidParameterException();
                            else{ //senao continua com a venda
                                Ingresso ingresso = null;
                                int id_ingresso = 0;
                                do{
                                    try{
                                    //pede o id do ingresso que o cliente quer
                                    id_ingresso = Console.readInt("Escolha o ID: ");
                                    //busca o ingresso no sistema
                                    ingresso = gerenciaIngressos.getObjetoPorId(id_ingresso, 0);
                                    //se é nulo lanca excecao
                                    if(ingresso==null)
                                        throw new InvalidParameterException();
                                    }
                                    catch(InvalidParameterException e){ //trata excecao
                                        System.out.println("ID inexistente!");
                                    }
                                }
                                while(ingresso == null);
                                //se o ingresso esta disponivel
                                if(ingresso.isDisponivel()){
                                    //selecionar forma de pagamento
                                    int forma=0;
                                    do{
                                        try{
                                            forma = Console.readInt("Ingresse a forma de pagamento: (1. CARTAO, 2. DINHEIRO)");
                                            if(forma<=0 && forma>2)//forma invalida lanca excecao
                                                throw new InvalidParameterException();
                                        }
                                        catch(InvalidParameterException e){ //trata excecao
                                            System.out.println("VALOR INVALIDO!");
                                        }

                                    }while(forma<=0 && forma>2);
                                    //atribui forma de pagamento
                                    Pagamento pagamento;
                                    if(forma == 1)
                                        pagamento = Pagamento.CARTAO;
                                    else
                                        pagamento = Pagamento.DINHEIRO;
                                    //cria a compra
                                    Compra compra = new Compra(id_ingresso, ingresso.getId_evento(), cliente.getCpf(), cliente.getNome(), Calendar.getInstance(), pagamento, ingresso.getSecao().getPreco());
                                    //da o desconto
                                    compra.setValor(compra.calcularDesconto());
                                    //se consegue gravar acompra
                                    if(gerenciaCompras.gravarObjeto(compra)){
                                        try{
                                            //poe o ingresso indisponivel
                                            gerenciaIngressos.remove(ingresso);
                                            ingresso.setDisponivel(false);
                                            gerenciaIngressos.gravarObjeto(ingresso);
                                            //modifica arrecadacao e vendas do evento
                                            Evento evento = gerenciaEventos.getObjetoPorId(ingresso.getId_evento(), 0);
                                            gerenciaEventos.remove(evento);
                                            evento.setArrecadacao(evento.getArrecadacao()+compra.getValor());
                                            evento.setVendas(evento.getVendas()+1);
                                            gerenciaEventos.gravarObjeto(evento);
                                            //mensagem
                                            System.out.println("Compra realizada com sucesso! Valor final: R$" + compra.getValor());
                                    }
                                        catch(NullPointerException e){ //erro evento/ingresso inexistente
                                            System.out.println("ERRO! Dado nao encontrado.");
                                        }
                                    }
                                    else //compra nao realizada
                                        System.out.println("ERRO! Compra nao realizada!");
                                }
                            else{//se o ingresso nao esta disponivel
                                System.out.println("Ingresso indisponivel. ");
                            }    
                        }
                    }}
                    catch(InvalidParameterException e){ //cliente nao esta cadastrado
                        System.out.println("Cliente nao cadastrado! Realize o cadastro antes da compra.");
                    }
                    catch(IllegalArgumentException e){ //nao tem argumento (evento) cadastrado
                        System.out.println("Cadastre um evento primeiro para ter acesso a esta secao.");
                    }
                    break;
                }
                case 2:{ //desfazer venda de ingresso
                    try{
                        //pede id do ingresso
                        int id_ingresso = Console.readInt("Ingresse o ID do ingresso: ");
                        //verifica se existe a compra do ingresso
                        Compra compra = gerenciaCompras.getObjetoPorId(id_ingresso, 0);
                        //se nao existe lanca excecao
                        if(compra == null) 
                            throw new InvalidParameterException();
                        else{//se a compra existe exclui
                            //se conseguiu excluir sem problemas
                            if(gerenciaCompras.remove(compra)){
                                try{
                                    //deixa ingresso disponivel de novo
                                    Ingresso ingresso = gerenciaIngressos.getObjetoPorId(id_ingresso, 0);
                                    gerenciaIngressos.remove(ingresso);
                                    ingresso.setDisponivel(true);
                                    gerenciaIngressos.gravarObjeto(ingresso);
                                    //diminui vendas e arrecadacao do evento
                                    Evento evento = gerenciaEventos.getObjetoPorId(ingresso.getId_evento(), 0);
                                    gerenciaEventos.remove(evento);
                                    evento.setArrecadacao(evento.getArrecadacao()-compra.getValor());
                                    evento.setVendas(evento.getVendas()-1);
                                    gerenciaEventos.gravarObjeto(evento);
                                    //mensagem
                                    System.out.println("Compra removida com sucesso.");
                                }
                                catch(NullPointerException e){ //erro evento/ingresso inexistente
                                    System.out.println("ERRO! Dado nao encontrado.");
                                }
                            }
                            else //se nao conseguiu remover
                                System.out.println("ERRO. Compra nao removida.");
                        }
                    }
                    catch(InvalidParameterException e){ //trata excecao de compra inexistente
                        System.out.println("Nao existe compra com o ID informado cadastrada no sistema.");
                    }
                    break;
                }
                case 3: { //listar ingressos
                    gerenciaIngressos.imprimeObjetos();
                    break;
                }
                case 4: { //listar vendas
                    gerenciaCompras.imprimeObjetos();
                    break;
                }
                
                default: {
                    mensagemDefault(opcao2);
                    break;
                }
            }
            
        }while(opcao2!=0);
}    
    
    private static void mensagemDefault(int opcao2) {
        System.out.println("");
        if(opcao2!=0)
            System.out.println("Opcao inválida!");
        else
            System.out.println("Voltando ao menu principal...");
    }
}
    
