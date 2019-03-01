/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package eventos.model;

/**
 *
 * @author alunoinf
 */
public class Ingresso {
    private int id, cadeira, id_evento;
    private Secao secao;
    private boolean disponivel;        
    public Ingresso(int id, int cadeira, Secao secao, int id_evento, boolean disponivel) {
        this.id = id;
        this.cadeira = cadeira;
        this.id_evento = id_evento;
        this.secao = secao;
        this.disponivel = disponivel;
    }
    
    public boolean isDisponivel() {
        return disponivel;
    }

    public void setDisponivel(boolean disponivel) {
        this.disponivel = disponivel;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }
    
    public int getCadeira() {
        return cadeira;
    }

    public void setCadeira(int cadeira) {
        this.cadeira = cadeira;
    }

    public int getId_evento() {
        return id_evento;
    }

    public void setId_evento(int id_evento) {
        this.id_evento = id_evento;
    }

    public Secao getSecao() {
        return secao;
    }

    public void setSecao(Secao secao) {
        this.secao = secao;
    }
    
    public void imprimirIngresso(){
        System.out.println("");
        System.out.print("ID "+ this.getId() + ", cadeira " + this.getCadeira() + ", secao " 
            + this.getSecao() + ", evento " + this.getId_evento() + ": "); 
            if(this.isDisponivel())
                    System.out.println("DISPONIVEL");
                else
                    System.out.println("Indisponivel");
    }
    
    public int calcularId(){
        int id = this.getId_evento()*1000 + this.getSecao().getCodigo() * 100 + this.getCadeira();
        return id;
    }
}

