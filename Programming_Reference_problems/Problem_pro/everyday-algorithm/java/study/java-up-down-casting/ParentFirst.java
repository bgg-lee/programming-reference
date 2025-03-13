public class ParentFirst { 
    public int age = 55; 
    public String name = "첫번째 부모"; 
    
    public void print(int age, String name){
        this.age = age;
        this.name = name;
        System.out.println("ParentFirst method :" + age);
        System.out.println("ParentFirst method :" + name);
    }
}
