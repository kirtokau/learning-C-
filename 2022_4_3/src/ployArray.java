public class ployArray {
    public static void main(String[] args) {
        //2个Student对象和2个Teacher对象,统一放在数组中，并调用每个对象的say方法
        Person[] persons=new Person[5];
        persons[0]=new Person("jack",20);
        persons[1]=new Student("maly",18,100);
        persons[2]=new Student ("smith",19,30.1);
        persons[3]=new Teacher("scoot",30,20000);
        persons[4]=new Teacher("King",50,25000);
        for (int i=0;i<persons.length;i++){
            //persons[i].say();//动态绑定机制
            System.out.println(persons[i].say());
            if(persons[i] instanceof  Student){
                //判断person[i]运行类型是否是Student
                Student student=(Student)persons[i];
                student.study();
                //((Student)persons[i]).study();//向下转型
            }else if(persons[i] instanceof Teacher){
                Teacher teacher=(Teacher)persons[i];
                teacher.teach();
            }else if(persons[i] instanceof Person){

            }else{
                System.out.println("你的类型有误，请自己检查...");
            }
        }


    }

}
