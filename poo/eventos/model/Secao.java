/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package eventos.model;

/**
 *
 * @author alunoinf
 */
public enum Secao {
    /**
     *
     */
    NORMAL(1, 40.00f),
    VIP(2, 90.00f); 
    private final int codigo; 
    private final float preco; 
    
    private Secao(int codigo, float preco){
        this.codigo = codigo;
        this.preco = preco;
    }
    
    public int getCodigo(){
        return this.codigo;
    }
    public float getPreco(){
        return this.preco;
    }
    
}

