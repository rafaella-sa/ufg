package eventos.comum;
/**
 * @author Carlos André Athaide, Gonçalo Serafim, Rafaella Almeida
 */
public class Menu {
    private final int quantItens=10;
	private final String[] itens;
	private int atual;
	public Menu(){
		itens=new String[quantItens];
		itens[0]="Sair";
		atual=1;
	}
		
	public void agregarItem(String item){
		itens[atual]=item;
		atual++;
	}
		
	public void eliminarItem(int num){
		if(num>0 & num<atual){}		
	}
	
	public void eliminarTodos(){};
		
	public int executarMenu(){
		System.out.println("*** Menu ***");
		for(int i=1; i<atual; i++)
			System.out.println(i+". "+itens[i]);
		System.out.println("0. "+itens[0]);
		System.out.println();
		System.out.print("Opcao a escolher: ");
		int opcao= Console.readInt();
		return opcao;
	}
}
