package eventos.model;

public enum Pagamento {
    CARTAO(1), 
    DINHEIRO(2);
    
    private final int id;
    
    private Pagamento(int id){
        this.id = id;
    }
    
    public int getId(){
        return this.id;
    }
}
