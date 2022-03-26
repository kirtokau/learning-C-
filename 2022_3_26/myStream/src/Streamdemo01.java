import java.util.ArrayList;

public class Streamdemo01 {
    public static void main(String[] args) {
        ArrayList<String>list=new ArrayList<>();
        list.add("林青霞");
        list.add("张曼玉");
        list.add("王祖贤");
        list.add("柳岩");
        list.add("张敏");
        list.add("张无忌");
        list.stream().filter((String s)-> {
            return s.startsWith("张");
        }).forEach(System.out::println);

       // list.stream().filter(s->s.startsWith("张")).forEach(System.out::println);
       System.out.println("--------");
       //输出list集合中长度为3的元素
       list.stream().filter(s->s.length()==3).forEach(System.out::println);
        System.out.println("--------");
        //输出list集合中长度为3以"张"开头的元素
       list.stream().filter(s->s.startsWith("张")).filter(s->s.length()==3).forEach(System.out::println);




    }


}
