/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package eventos.model;

import java.util.Calendar;

/**
 *
 * @author alunoinf
 */
public class Compra {
        private int id_evento;
    	private Calendar data;
        private Pagamento pagamento;
        private int id_ingresso;
        private int cpf_cliente;
        private float valor;
        private String nomecliente;
        
        public Compra(int id_ingresso, int id_evento, int cpf_cliente, String nomecliente, 
                Calendar data, Pagamento pagamento, float valor){
            this.id_ingresso = id_ingresso;
            this.id_evento = id_evento;
            this.cpf_cliente = cpf_cliente;
            this.nomecliente = nomecliente;
            this.data = data;
            this.pagamento = pagamento;
            this.valor = valor;
        }
        
    public int getId_evento() {
        return id_evento;
    }

    public void setId_evento(int id_evento) {
        this.id_evento = id_evento;
    }
        
        
       public int getCpf_cliente() {
            return cpf_cliente;
       }

       public void setCpf_cliente(int cpf_cliente) {
            this.cpf_cliente = cpf_cliente;
       } 
    public int getId_ingresso() {
        return id_ingresso;
    }

    public void setId_ingresso(int id_ingresso) {
        this.id_ingresso = id_ingresso;
    }

    public Calendar getData() {
        return data;
    }

    public void setData(Calendar data) {
        this.data = data;
    }
        public Pagamento getPagamento() {
        return pagamento;
    }

    public void setPagamento(Pagamento pagamento) {
        this.pagamento = pagamento;
    }
    
    public float getValor() {
        return this.valor;
    }

    public void setValor(float valor){
        this.valor = valor;
    }
    
    public float calcularDesconto(){
        float valor = this.getValor();
        if(this.getPagamento() == Pagamento.DINHEIRO){
            if(valor <= 50.00f)
                    valor = valor - 1.00f;
                else
                    valor = valor * 0.98f;
	}
        return valor;
    }

    public String getNomecliente() {
        return nomecliente;
    }

    public void setNomecliente(String nomecliente) {
        this.nomecliente = nomecliente;
    }
    
    public void imprimirCompra(){
        System.out.println("Cadeira " + this.getId_ingresso() + ", comprado pelo cliente " + this.getNomecliente() + " de CPF " + this.getCpf_cliente() + ", Data " 
                + this.getData().get(Calendar.DAY_OF_MONTH) + "/" 
                + (this.getData().get(Calendar.MONTH)+1) + "/" 
                + this.getData().get(Calendar.YEAR) + ", pagamento com " 
                + this.getPagamento() + " , valor: " + this.getValor());
    }
}
