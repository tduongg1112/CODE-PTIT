package UDP;

import java.io.Serializable;


public class Student implements Serializable{
    private static final long serialVersionUID = 20171107L;
    private String id;
    private String code;
    private String name;
    private String email;
    
    public Student (String id, String code, String name, String email){
        this.id = id;
        this.code = code;
        this.name = name;
        this.email = email;
    }
    
    public Student(String code){
        this.code = code;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
    
    public void info(){
        System.out.println("Name: " + this.name);
        System.out.println("Email: " + this.email);
    }
}
