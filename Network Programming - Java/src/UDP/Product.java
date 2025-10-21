package UDP;

import java.io.*;

public class Product implements Serializable {
    private static final long serialVersionUID = 20161107;
    private String id;
    private String code;
    private String name;
    private int quantity;
    
    public Product (String id, String code, String name, int quantity){
        this.id = id;
        this.code = code;
        this.name = name;
        this.quantity = quantity;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getQuantity() {
        return quantity;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }
    
    public void info(){
        System.out.println("Name: " + this.name);
        System.out.println("Quantity: " + this.quantity);
    }
}
