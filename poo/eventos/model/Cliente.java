/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package eventos.model;

/**
 *
 * @author alunoinf
 */
public class Cliente {
    private String nome;
    private int cpf;
    private Endereco endereco;
    private String telefone;
    public Cliente(int cpf, String nome, Endereco endereco, String telefone) {
		this.nome = nome;
		this.cpf = cpf;
		this.endereco = endereco;
		this.telefone = telefone;
    }
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public int getCpf() {
		return cpf;
	}
	public void setCpf(int cpf) {
		this.cpf = cpf;
	}
	public Endereco getEndereco() {
		return endereco;
	}
	public void setEndereco(Endereco endereco) {
		this.endereco = endereco;
	}
	public String getTelefone() {
		return telefone;
	}
	public void setTelefone(String telefone) {
		this.telefone = telefone;
	}
        
        public void imprimirCliente(){
            System.out.println("");
            System.out.println("NOME: " + this.getNome());
            System.out.println("CPF: " + this.getCpf());  
            System.out.println("ENDERECO");
            System.out.println("Rua/Avenida: " + this.getEndereco().getRua());
            System.out.println("Numero: " + this.getEndereco().getNumero());
            System.out.println("Complemento: " + this.getEndereco().getComplemento());
            System.out.println("Bairro: " + this.getEndereco().getBairro());
            System.out.println("CEP: " + this.getEndereco().getCep());
            System.out.println("TELEFONE: " + this.getTelefone());           
        }
}

