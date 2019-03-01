package eventos.model;
import java.util.Calendar;
/**
 * @author Carlos André Athaide, Gonçalo Serafim, Rafaella Almeida
 */
public class Evento {
    private String nome, descricao, local;
    private Calendar data;
    private int id;
    private float arrecadacao;
    private int vendas; 
  
    public Evento(int id, String nome, String descricao, Calendar data, 
            String local, float arrecadacao, int vendas) {
        this.id = id;
        this.nome = nome;
        this.descricao = descricao;
	this.data = data;	
	this.local = local;
        this.arrecadacao = arrecadacao;
        this.vendas = vendas;
	}

    public int getVendas() {
        return vendas;
    }

    public void setVendas(int vendas) {
        this.vendas = vendas;
    }
        
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
        public Calendar getData() {
		return data;
	}
	public void setData(Calendar data) {
		this.data = data;
	}
	public String getDescricao() {
		return descricao;
	}
	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}
	public String getLocal() {
		return local;
	}
	public void setLocal(String local) {
		this.local = local;
	}
	
         public float getArrecadacao() {
		return arrecadacao;
	}

        public void setArrecadacao(float arrecadacao) {
            this.arrecadacao = arrecadacao;
        }
        public void imprimirEvento(){
            System.out.println("");
            System.out.println("ID: " + this.getId());
            System.out.println("NOME: " + this.getNome());
            System.out.println("DESCRICAO: " + this.getDescricao());
            System.out.println("DATA: " + 
            this.getData().get(Calendar.DAY_OF_MONTH) + "/"  
            + (this.getData().get(Calendar.MONTH)+1) + "/" 
            + this.getData().get(Calendar.YEAR));
            System.out.println("LOCAL: " + this.getLocal());
            System.out.println("QUANTIDADE DE VENDAS: " + this.getVendas());
            System.out.println("ARRECADACAO: R$ "                                        
            + this.getArrecadacao());          
        }
}

