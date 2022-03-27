public class ReflectDemo01 {
    public static void main(String[] args) {
        //三种方式获取字节码对象
        Class<Student> c1 = Student.class;
        System.out.println(c1);
        Class<Student> c2 = Student.class;
        System.out.println(c1==c2);
        System.out.println("--------");
        Student s=new Student();
        Class<? extends Student> c3 = s.getClass();
        System.out.println(c1==c3);
        System.out.println("--------");
        try {
            Class<?> c4 = Class.forName("Student");
            System.out.println(c1==c4);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
