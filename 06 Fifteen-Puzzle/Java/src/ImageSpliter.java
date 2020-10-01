import java.awt.Color;
import java.awt.Dimension;
import java.awt.image.BufferedImage;
import javax.swing.ImageIcon;

public class ImageSpliter {
    public ImageSpliter() {
    }

    static Cell[] Splitter(BufferedImage img, int level) {
        int x = 0;
        int y = 0;
        int count = 0;
        int figureWidth = img.getWidth() / level;
        int figureHeight = img.getHeight() / level;
        Cell[] cells = new Cell[level * level];

        for(int i = 0; i < level; ++i) {
            for(int j = 0; j < level; ++j) {
                if (i == level - 1 && j == level - 1) {
                    cells[count] = new Cell((ImageIcon)null, count);
                    cells[count].setPreferredSize(new Dimension(figureWidth, figureHeight));
                    cells[count].setBackground(Color.BLACK);
                } else {
                    cells[count] = new Cell(new ImageIcon(img.getSubimage(x, y, figureWidth, figureHeight)), count);
                    cells[count].setPreferredSize(new Dimension(figureWidth, figureHeight));
                    x += figureWidth;
                    ++count;
                }
            }

            x = 0;
            y += figureHeight;
        }

        return cells;
    }
}
