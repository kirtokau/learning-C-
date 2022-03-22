import java.io.File;
import java.io.IOException;
import java.sql.SQLOutput;

//如果文件不存在就创建文件，并返回true
//如果文件存在就不创建文件，并返回false
public class FileDemo02 {
    public static void main(String[] args) throws IOException {
        File f1=new File("D:\\itcast\\java.txt");
        System.out.println(f1.createNewFile());
        System.out.println("--------");
        //如果目录不存在就创建文件，并返回true
       //如果目录存在就不创建文件，并返回false
        File f2=new File("D:\\itcast\\javase");
        System.out.println(f2.mkdir());
        System.out.println("--------");
        File f3=new File("D:\\itcast\\javaweb\\HTML");
       // System.out.println(f3.mkdir());
        System.out.println(f3.mkdirs());
        System.out.println("--------");
        File f4=new File("D:\\itcast\\javase.txt");
        System.out.println(f4.createNewFile());


    }




}
