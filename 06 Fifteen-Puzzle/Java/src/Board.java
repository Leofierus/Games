import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;
public class Board extends JPanel {
    BufferedImage img;
    int curPos;
    Board(BufferedImage img){
        setPreferredSize(new Dimension(img.getHeight(),img.getWidth()));
        setBorder(BorderFactory.createLineBorder(Color.BLUE, 2));
        setBackground(Color.BLACK);
        this.img=img;
        setLayout(new GridLayout(3,3));
    }
    void add(){
        Cell[] cells= ImageSpliter.Splitter(img);
        for(Cell cell:cells){
            add(cell);
        }
        curPos=3*3-1;
    }
    boolean check(){
        for(int i=0;i<8;i++){
            Cell cell=(Cell)getComponent(i);
            if(i!=cell.solPos)
                return false;
        }
        return true;
    }
    void shuffle(){
        for(int i=0;i<100;i++){
            int random=(int)Math.round(Math.random()*3);
            switch(random){
                case 0:swap(MoveCell.up(curPos));break;
                case 1:swap(MoveCell.down(curPos));break;
                case 2:swap(MoveCell.left(curPos));break;
                case 3:swap(MoveCell.right(curPos));break;
            }
        }

    }
    void swap(int newPos){
        if(newPos==-1){
            return;
        }
        int firstIndex;
        int secondIndex;
        if(newPos>curPos){
            firstIndex=curPos;
            secondIndex=newPos;
        }
        else{
            firstIndex=newPos;
            secondIndex=curPos;
        }
        Component first=getComponent(firstIndex);
        Component second=getComponent(secondIndex);
        remove(first);
        remove(second);
        add(second,firstIndex);
        add(first,secondIndex);
        curPos=newPos;
    }

}

