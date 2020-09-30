import javax.swing.*;

public class Cell extends JLabel {
    int solPos;
    ImageIcon icon;
    Cell(ImageIcon icon,int solPos){
        this.icon=icon;
        this.solPos=solPos;
        setIcon(icon);
    }
}
