package eventos.persistencia.impl;

import java.util.List;
public interface ServiceHelper <T extends Object>{    
    public static final char SEPARADOR = ';';   
    public boolean gravarObjeto(T object);
    public void gravarObjetos(List<T> object);
    public T getObjetoPorId(int id, int posicao);
    public List<T> getTodosObjetos();
    public boolean remove(T Object);
    public boolean imprimeObjetos();
}

