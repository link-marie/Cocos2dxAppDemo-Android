package com.linknext.cocos2dx;

/**
 */
public class JniIf {

    static public String testString(){
        return "test_string";
    }

    static public int testInt1(){
        return 10;
    }

    static public int testInt2( int i){
        return 10 * i;
    }

    static public float testFloat1(){
        return 1.333f;
    }

    static public float testFloat2( int i){
        return 1.333f * i;
    }

    static public double testDouble2( int i){
        return 2.666f * i;
    }

}
