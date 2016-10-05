import java.util.HashMap;
import java.util.Map;

public class MultiHashTable {
    private final Map<Integer, Integer> map = new HashMap<>();

    public void updateValue(int key, int value){
        Integer c = map.get(key);

        if (c == null)
            map.put(key, value);
        else
            map.put(key, c + value);
    }

    public int getValue(int key){
        Integer c = map.get(key);

        if (c == null)
            return 0;
        else
            return c;
    }
}
