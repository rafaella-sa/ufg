package eventos.persistencia.base;

import eventos.model.Secao;
import eventos.persistencia.impl.ServiceHelper;
import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class CSVToFile {
	private String nomeArquivo;

	public CSVToFile(String nomeArquivo){
		this.nomeArquivo = nomeArquivo;
		criarArquivo();
	}

	public void setNomeArquivo(String nomeArquivo){
		this.nomeArquivo = nomeArquivo;
	}

	private boolean montarArquivo() {
		File arquivo = new File(nomeArquivo);
		if (arquivo.exists()) {
			return true;
		} else {
			try {
				if (arquivo.createNewFile()) {
					return true;
				}
			} catch (IOException e) {
				return false;
			}
		}
		return false;
	}

	private boolean criarArquivo() {
		if (nomeArquivo != null) {
			return montarArquivo();
		}
		return false;
	}
	
	private boolean arquivoExiste() {
		if (nomeArquivo != null) {
			File arquivo = new File(nomeArquivo);
			return arquivo.exists();
		}
		return false;
	}

	public boolean gravarLinha(Object object) {
		if (arquivoExiste()) {
			BufferedWriter writer = null;
			try {
				writer = new BufferedWriter(new FileWriter(nomeArquivo, true));
				writer.append(object.toString());
				writer.newLine();
				writer.close();
				return true;
			} catch (IOException ex) {
				System.out.println("Falha ao escrever no arquivo.");
			}
		}
		return false;
	}

	public String getLinhaPorId(int id, int posicaoAtributo){
	    BufferedReader reader = null;
	    String linha = null;
	    try {
	        reader = new BufferedReader(new FileReader(nomeArquivo));
	            while((linha = reader.readLine()) != null){
	                String[] leitura = linha.split(String.valueOf(
                                ServiceHelper.SEPARADOR));
	                try{
	                	if(Integer.parseInt(leitura[posicaoAtributo]) == id){
	                		reader.close();
	                		return linha;
	                	}
	                }catch(NumberFormatException e){
	                	e.printStackTrace();
	                }
	            }
	        reader.close();
	    } catch (IOException ie) { }
		return null;
	}
        
        public void setLinhaPorId(int id, int posicaoAtributo, String newLinha){
	    BufferedReader reader = null;
	    String linha = null;
	    try {
	        reader = new BufferedReader(new FileReader(nomeArquivo));
	            while((linha = reader.readLine()) != null){
	                String[] leitura = linha.split(String.valueOf(
                                ServiceHelper.SEPARADOR));
	                try{
	                	if(Integer.parseInt(leitura[posicaoAtributo]) == id){
                                    linha = newLinha;
                                    reader.close();
                                    }
	                }catch(NumberFormatException e){
	                	e.printStackTrace();
	                }
	            }
	        reader.close();
	    } catch (IOException ie) { }
		
	}
	public List<String> getLinhas(){
		List<String> objetos = new ArrayList<String>();
		BufferedReader reader = null;
	    String linha = null;
	    try {
	        reader = new BufferedReader(new FileReader(nomeArquivo));
	            while((linha = reader.readLine()) != null){
	                objetos.add(linha);
	            }
	        reader.close();
	    } catch (IOException ie) {
	    	return null;
	    }
		return objetos;
	}
	
	public List<String> getObjetosPorAtributo(int id, int posicaoAtributo){
		List<String> objetos = new ArrayList<String>();
		BufferedReader reader = null;
	    String linha = null;
	    try {
	        reader = new BufferedReader(new FileReader(nomeArquivo));
	            while((linha = reader.readLine()) != null){
	            	 String[] leitura = linha.split(String.valueOf(
                                ServiceHelper.SEPARADOR));
	                try{
	                	if(Integer.parseInt(leitura[posicaoAtributo]) == id){
	                		objetos.add(linha);
	                	}
	                }catch(NumberFormatException e){
	                	e.printStackTrace();
	                }catch(ArrayIndexOutOfBoundsException e){
	                	e.printStackTrace();
	                }
	            }
	        reader.close();
	    } catch (IOException ie) {
	    	return null;
	    }
		
		return objetos;
	}
        
        public boolean contem(int id){
            BufferedReader reader = null;
	    String linha = null;
	    try {
	        reader = new BufferedReader(new FileReader(nomeArquivo));
	            while((linha = reader.readLine()) != null){
	                String[] leitura = linha.split(String.valueOf(
                                ServiceHelper.SEPARADOR));
	                try{
	                	if(Integer.parseInt(leitura[0]) == id){
	                		reader.close();
	                		return true;
	                	}
	                }catch(NumberFormatException e){
	                	e.printStackTrace();
	                }
	            }
	        reader.close();
	    } catch (IOException ie) { 
                return false;
            }
		return false;
        }
        
     /*   public boolean contemIngresso(Id_Ingresso id){
            BufferedReader reader = null;
	    String linha = null;
	    try {
	        reader = new BufferedReader(new FileReader(nomeArquivo));
	            while((linha = reader.readLine()) != null){
	                String[] leitura = linha.split(String.valueOf(
                                ServiceHelper.SEPARADOR));
	                try{
	                	if(Integer.parseInt(leitura[0]) == id.getCadeira() 
                                        && Secao.valueOf(leitura[1]) == id.getSecao() 
                                        && Integer.parseInt(leitura[2]) == id.getId_evento()){
	                		reader.close();
	                		return true;
	                	}
	                }catch(NumberFormatException e){
	                	e.printStackTrace();
	                }
	            }
	        reader.close();
	    } catch (IOException ie) { 
                return false;
            }
		return false;
        }*/
        public boolean removerLinha(int id) {
		File arquivo = new File(nomeArquivo);
		File arquivoTemporario = null;
		BufferedReader reader = null;
		PrintWriter printWrite = null;
		String linha = null;
		try {
			reader = new BufferedReader(new FileReader(arquivo));
			arquivoTemporario = new File(arquivo.getAbsolutePath() + ".tmp");
			printWrite = new PrintWriter(new FileWriter(arquivoTemporario));
			while ((linha = reader.readLine()) != null) {
                                String[] campos = linha.trim().split(
                                        String.valueOf(ServiceHelper.SEPARADOR));
                                int identificador = Integer.parseInt(campos[0]);
				if (id != identificador) {
					printWrite.println(linha);
					printWrite.flush();
				}
			}
			reader.close();
			printWrite.close();
		} catch (IOException ie) {
			return false;
		}
		if (!arquivo.delete()) {
			return false;
		}
		if (!arquivoTemporario.renameTo(arquivo)) {
			return false;
		}
		return true;
	}
       /* public boolean removerLinhaIngresso(Id_Ingresso id) {
		File arquivo = new File(nomeArquivo);
		File arquivoTemporario = null;
		BufferedReader reader = null;
		PrintWriter printWrite = null;
		String linha = null;
		try {
			reader = new BufferedReader(new FileReader(arquivo));
			arquivoTemporario = new File(arquivo.getAbsolutePath() + ".tmp");
			printWrite = new PrintWriter(new FileWriter(arquivoTemporario));
			while ((linha = reader.readLine()) != null) {
                                String[] campos = linha.trim().split(
                                        String.valueOf(ServiceHelper.SEPARADOR));
                                int cadeira = Integer.parseInt(campos[0]);
                                Secao secao = Secao.valueOf(campos[1]);
                                int id_evento = Integer.parseInt(campos[2]);
                                Id_Ingresso identificador = new Id_Ingresso(cadeira, secao, id_evento);
                                if (id != identificador) {
					printWrite.println(linha);
					printWrite.flush();
				}
			}
			reader.close();
			printWrite.close();
		} catch (IOException ie) {
			return false;
		}
		if (!arquivo.delete()) {
			return false;
		}
		if (!arquivoTemporario.renameTo(arquivo)) {
			return false;
		}
		return true;
	}*/
}




