package UDP;

import java.io.*;
import java.net.*;

public class Employee implements Serializable{
    private static final long serialVersionUID = 20261107L;
    private String id;
    private String name;
    private String hireDate;
    private double salary;
    
    public Employee (String id, String name, String hireDate, double salary){
        this.id = id;
        this.name = name;
        this.hireDate = hireDate;
        this.salary = salary;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getHireDate() {
        return hireDate;
    }

    public void setHireDate(String hireDate) {
        this.hireDate = hireDate;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }
    
    @Override
    public String toString(){
        return this.id + "\n" + this.name + "\n" + this.salary + "\n" + this.hireDate;
    }
}
