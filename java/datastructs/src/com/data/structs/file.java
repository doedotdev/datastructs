package com.data.structs;

import java.io.*;

/**
 * Created by benjamin.horn on 3/4/17.
 */
public class file {
    String file_contents; // all file contents in one string
    String[] file_contents_ary;

    public file() {
        this.file_contents = null;
        this.file_contents_ary = null;
    }

    public void print(){
        System.out.println(file_contents);
    }

    public String retStr(){
        return file_contents;
    }

    public String[] retStrAry(){
        return file_contents_ary;
    }

    public void clean(){
        file_contents = file_contents.replace("\n", " ").replace("\r", " ");
        file_contents = file_contents.toLowerCase();
    }


    public void in(String filename) throws IOException {
        File file = new File(filename); //for ex foo.txt
        FileReader reader = null;
        try {
            reader = new FileReader(file);
            char[] chars = new char[(int) file.length()];
            reader.read(chars);
            file_contents = new String(chars);
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if(reader !=null){reader.close();}
        }
        clean(); // clean up the file.
        file_contents_ary = file_contents.split(" ");
    }


}
