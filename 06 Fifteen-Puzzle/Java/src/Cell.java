import javax.swing.ImageIcon;
import javax.swing.JLabel;

public class Cell extends JLabel {
    int solPos;
    ImageIcon icon;

    Cell(ImageIcon icon, int solPos) {
        this.icon = icon;
        this.solPos = solPos;
        this.setIcon(icon);
    }
}
