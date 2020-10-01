import java.awt.Color;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.image.BufferedImage;
import javax.swing.BorderFactory;
import javax.swing.JPanel;

public class Board extends JPanel {
    BufferedImage img;
    int level;
    int curPos;

    Board(BufferedImage img, int level) {
        this.setPreferredSize(new Dimension(img.getHeight(), img.getWidth()));
        this.setBorder(BorderFactory.createLineBorder(Color.BLUE, 2));
        this.setBackground(Color.BLACK);
        this.img = img;
        this.level = level;
        this.setLayout(new GridLayout(level, level));
    }

    void add() {
        Cell[] cells = ImageSpliter.Splitter(this.img, this.level);
        Cell[] var2 = cells;
        int var3 = cells.length;

        for(int var4 = 0; var4 < var3; ++var4) {
            Cell cell = var2[var4];
            this.add(cell);
        }

        this.curPos = this.level * this.level - 1;
    }

    boolean check() {
        for(int i = 0; i < this.level * this.level - 1; ++i) {
            Cell cell = (Cell)this.getComponent(i);
            if (i != cell.solPos) {
                return false;
            }
        }

        return true;
    }

    void shuffle() {
        for(int i = 0; i < 100; ++i) {
            int random = (int)Math.round(Math.random() * 3.0D);
            switch(random) {
                case 0:
                    this.swap(MoveCell.up(this.curPos, this.level));
                    break;
                case 1:
                    this.swap(MoveCell.down(this.curPos, this.level));
                    break;
                case 2:
                    this.swap(MoveCell.left(this.curPos, this.level));
                    break;
                case 3:
                    this.swap(MoveCell.right(this.curPos, this.level));
            }
        }

    }

    void swap(int newPos) {
        if (newPos != -1) {
            int firstIndex;
            int secondIndex;
            if (newPos > this.curPos) {
                firstIndex = this.curPos;
                secondIndex = newPos;
            } else {
                firstIndex = newPos;
                secondIndex = this.curPos;
            }

            Component first = this.getComponent(firstIndex);
            Component second = this.getComponent(secondIndex);
            this.remove(first);
            this.remove(second);
            this.add(second, firstIndex);
            this.add(first, secondIndex);
            this.curPos = newPos;
        }
    }
}