/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package eventos.model;

/**
 *
 * @author alunoinf
 */
public class Endereco {
    private String rua, complemento, bairro;
	private int numero, cep;
    public Endereco(String rua, int numero, String complemento, 
                String bairro, int cep) {
		this.rua = rua;
		this.complemento = complemento;
		this.bairro = bairro;
		this.numero = numero;
		this.cep = cep;
	}
	public String getRua() {
		return rua;
	}
	public void setRua(String rua) {
		this.rua = rua;
	}
	public String getComplemento() {
		return complemento;
	}
	public void setComplemento(String complemento) {
		this.complemento = complemento;
	}
	public String getBairro() {
		return bairro;
	}
	public void setBairro(String bairro) {
		this.bairro = bairro;
	}
	public int getNumero() {
		return numero;
	}
	public void setNumero(int numero) {
		this.numero = numero;
	}
	public int getCep() {
		return cep;
	}
	public void setCep(int cep) {
		this.cep = cep;
	}
}
