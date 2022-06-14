import java.util.ArrayList;
import java.util.List;

public class TEST {

    public static void main(String[] args) {
//        ForTest();
        bianli();
    }
    public static void ForTest(){

        Sdff sdff = new Sdff();
        for (int i = 0; i<=8; i++){

            sdff.setId(i);
            sdff.setName("name"+i);
            LISTJI.sdffList.add(sdff);
//            System.out.println(LISTJI.sdffList.get(i));
        }
    }

    public  static void bianli(){
        ForTest();
//        System.out.println(LISTJI.sdffList.get(1));
        for (Sdff c: LISTJI.sdffList) {
            System.out.println("我是ID"+c);
            System.out.println("我是name:"+c.getName());
        }
    }
}
