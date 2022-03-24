import java.util.ArrayList;
import java.util.Iterator;

public class ArrayListdemo {
    public static void main(String[] args) {
        ArrayList<Student> array = new ArrayList<Student>();
        Student s1 = new Student("林青霞", 30);
        Student s2 = new Student("张曼玉", 35);
        Student s3 = new Student("王祖贤", 33);
        array.add(s1);
        array.add(s2);
        array.add(s3);
        Iterator<Student> it = array.iterator();
        while (it.hasNext()) {
            Student s = it.next();
            System.out.println(s.getName() + "," + s.getAge());

        }
        System.out.println("--------");
        for(int i=0;i<array.size();i++)
        {
            Student s=array.get(i);
            System.out.println(s.getName()+","+s.getAge());

        }
        System.out.println("--------");
        for(Student s:array)
        {
            System.out.println(s.getName() + "," + s.getAge());
        }




    }


}
