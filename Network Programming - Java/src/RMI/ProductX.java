package RMI;

import java.io.Serializable;

public class ProductX implements Serializable{
    private static final long serialVersionUID = 20171107;
    private String id;
    private String code;
    private String discountCode;
    private int discount;
    
    public ProductX (String id, String code, String discountCode, int discount){
        this.id = id;
        this.code = code;
        this.discountCode = discountCode;
        this.discount = discount;
    }

    public String getDiscountCode() {
        return discountCode;
    }

    public void setDiscountCode(String discountCode) {
        this.discountCode = discountCode;
    }

    public int getDiscount() {
        return discount;
    }

    public void setDiscount(int discount) {
        this.discount = discount;
    }
    
    @Override
    public String toString(){
        return this.discountCode + " " + this.discount;
    }
    
}
