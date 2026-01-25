// 2. Provide an example of multi-level inheritance of your choice.

// Parent class (First parent)
class Organization {
    // Instance Variable
    private String orgName;

    // Method to set instance variable
    public void setOrgName(String orgName) {
        this.orgName = orgName;
    }

    // Method to display organization name
    public void displayOrgName() {
        System.out.println("Organization: " + orgName);
    }
}

// Child class of first parent class (It is also the second parent class)
class Hierarchy extends Organization {
    // Instance Variable
    private String position;

    // Method to set instance variable
    public void setPosition(String position) {
        this.position = position;
    }

    // Method to display position
    public void displayPosition() {
        System.out.println("Position: " + position);
    }
}

// Child Class of second parent class
class Skill extends Hierarchy {
    // Instance variable
    private String skillRequired;

    // Method to set instance variable
    public void setSkillRequired(String skillRequired) {
        this.skillRequired = skillRequired;
    }

    // Method to display skill required
    public void displaySkillRequired() {
        System.out.println("Skill required: " + skillRequired);
    }
}

// Main class
public class Two {
    public static void main(String[] args) {
        // Create instance
        Skill s1 = new Skill();
        // Parent and grandparent method
        s1.setOrgName("NCCS");
        s1.setPosition("Senior Coordinator");
        // Own method
        s1.setSkillRequired("Conceptual Skills");
        s1.displayOrgName(); // Grandparent method
        s1.displayPosition(); // Parent method
        s1.displaySkillRequired(); // Own method
    }
}