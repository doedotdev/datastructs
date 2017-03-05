package com.data.structs;

import org.junit.Assert;
import org.junit.Test;
import java.util.*;

import static org.junit.Assert.*;

/**
 * Created by benjamin.horn on 3/4/17.
 */
public class hashTest {
    @Test
    public void test1() throws Exception{
        hash object = new hash();
        assertEquals(object.size(),0);

    }

    @Test
    public void test2() throws Exception{
        hash object = new hash();
        object.insert("hello");
        assertTrue(object.isIn("hello"));
        assertFalse(object.isIn("apple"));
        assertEquals(object.size(),1);
    }

    @Test
    public void test3() throws Exception {
        // test print
        hash object = new hash();
        object.insert("hello");
        assertTrue(object.isIn("hello"));
        assertFalse(object.isIn("apple"));
        assertEquals(object.size(),1);
        System.out.println("Print Test 1 - Begin");
        object.print();
        System.out.println("Print Test 1 - End");
    }

    @Test
    public void test4() throws Exception {
        // test print
        hash object = new hash();
        String[] my_strings = {"hello", "how", "are", "you", "hello", "", "", ""};
        for(int i = 0 ; i < my_strings.length; i++){
            object.insert(my_strings[i]);
        }
        assertTrue(object.isIn("how"));
        assertFalse(object.isIn("apple"));
        assertEquals(object.size(),5);
        assertEquals(object.insertions, my_strings.length);
        System.out.println("Print Test 2 - Begin");
        object.print();
        System.out.println("Print Test 2 - End");
    }

    @Test
    public void test5() throws Exception {
        // take in file and hash all the values
        file object = new file();
        object.print();

        object.in("MobyDick.txt");
        object.print();

        hash object1 = new hash();

        String[] temp_ary = object.retStrAry();
        for(int i = 0 ; i < temp_ary.length; i++){
            object1.insert(temp_ary[i]);
        }

        object1.print();

    }

    @Test
    public void test6() throws Exception {
        // take in file and hash all the values
        file object = new file();
        object.print();

        object.in("MobyDick.txt");
        object.print();

        hash object1 = new hash();

        String[] temp_ary = object.retStrAry();
        for(int i = 0 ; i < temp_ary.length; i++){
            object1.insert(temp_ary[i]);
        }

        object1.print();

    }

    @Test
    public void test7() throws Exception {
        // take in file and hash all the values
        file object = new file();
        object.print();

        object.in("MobyDick.txt");
        object.print();

        hash object1 = new hash();

        String[] temp_ary = object.retStrAry();
        for(int i = 0 ; i < temp_ary.length; i++){
            object1.insert(temp_ary[i]);
        }

        object1.print();

    }

    @Test
    public void test8() throws Exception {
        // take in file and hash all the values
        file object = new file();
        object.print();

        object.in("Dickens-AChristmasCarol.txt");
        object.print();

        hash object1 = new hash();

        String[] temp_ary = object.retStrAry();
        for(int i = 0 ; i < temp_ary.length; i++){
            object1.insert(temp_ary[i]);
        }

        object1.print();

    }

}