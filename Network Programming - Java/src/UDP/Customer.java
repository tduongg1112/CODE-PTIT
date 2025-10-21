package UDP;

import java.io.*;

public class Customer implements Serializable {
    private static final long serialVersionUID = 20151107;
    private String id;
    private String code;
    private String name;
    private String dayOfBirth;
    private String userName;
    
    public Customer (String id, String code, String name, String dayOfBirth, String userName){
        this.name = name;
        this.id = id;
        this.code = code;
        this.dayOfBirth = dayOfBirth;
        this.userName = userName;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getCode() {
        return code;
    }

    public void setCode(String code) {
        this.code = code;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDayOfBirth() {
        return dayOfBirth;
    }

    public void setDayOfBirth(String dayOfBirth) {
        this.dayOfBirth = dayOfBirth;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }
    
    @Override
    public String toString(){
        return this.id + "\n" + this.code + "\n" + this.name + "\n" + this.dayOfBirth + "\n" + this.userName;
    }
}
