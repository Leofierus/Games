import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;

public class ImageSpliter {
    static Cell[] Splitter(BufferedImage img){
        final int figureWidth, figureHeight;
        int x=0,y=0,count=0;
        figureWidth = img.getWidth()/3;
        figureHeight = img.getHeight()/3;
        Cell[] cells= new Cell[9];
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(i == 2 && j == 2){
                    cells[count]=new Cell(null,count);
                    cells[count].setPreferredSize(new Dimension(figureWidth, figureHeight));
                    cells[count].setBackground(Color.BLACK);
                    continue;
                }
                cells[count]=new Cell(new ImageIcon(img.getSubimage(x, y, figureWidth, figureHeight)),count);
                cells[count].setPreferredSize(new Dimension(figureWidth, figureHeight));
                x += figureWidth;
                count++;
            }
            x = 0;
            y += figureHeight;
        }
        return cells;
    }
}
