package com.data.structs;
import java.util.*;

/**
 * Created by benjamin.horn on 3/4/17.
 */

// HASH MAP THAT COUNTS VALUES / OCCURRENCES
public class hash {
    HashMap<String, Integer> object = new HashMap<>();
    public int insertions; // total items inserted into the map. (NOT MAP SIZE)

    public hash() {
    }

    public int size(){
        return object.size();
    }

    public boolean isIn(String thing){
        return object.containsKey(thing); // if it is in the map
    }

    public int getCount(String thing){
        if(isIn(thing)){
            return object.get(thing);
        }
        else{
            return 0; // does not exist in the map
        }
    }

    public int insertions(){
        return insertions;
    }

    public void print(){
        Iterator it = object.entrySet().iterator();
        while(it.hasNext()){
            Map.Entry pair = (Map.Entry)it.next();
            System.out.println(pair.getKey() + " = " + pair.getValue());
            it.remove();
        }
    }

    public void printOrder(){
        // i cant be sure
    }


    public void insert(String thing){
        insertions++;
        if(isIn(thing)){
            object.put(thing, getCount(thing) +1);
        }
        else{
            object.put(thing, 1); // first time it occurred
        }
    }
}
