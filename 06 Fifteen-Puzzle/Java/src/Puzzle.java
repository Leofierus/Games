import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.image.BufferedImage;

public class Puzzle extends JFrame implements KeyListener {
    Board board;
    JPanel sample;
    JLabel miniImage;
    Puzzle(BufferedImage img){
        setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
        this.addKeyListener(this);
        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);

        sample=new JPanel();
        sample.setSize(800,300);
        sample.setBackground(Color.BLACK);
        miniImage=new JLabel();
        miniImage.setSize(300,300);
        miniImage.setIcon(new ImageIcon(img.getScaledInstance(300, 300, Image.SCALE_REPLICATE)));
        sample.add(miniImage,BorderLayout.SOUTH);
        setSize(new Dimension(800,800));
        board=new Board(img);
        board.add();
        board.shuffle();
        layout.setHorizontalGroup(
                layout.createSequentialGroup()
                    .addComponent(board)
                    .addComponent(sample)

        );
        layout.setVerticalGroup(
                layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                       .addComponent(board)
                        .addComponent(sample)
        );


        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }

    @Override
    public void keyTyped(KeyEvent keyEvent) {

    }

    @Override
    public void keyPressed(KeyEvent keyEvent) {


    }

    @Override
    public void keyReleased(KeyEvent keyEvent) {
        if(keyEvent.getKeyCode()==KeyEvent.VK_S||keyEvent.getKeyCode()==KeyEvent.VK_DOWN){
            board.swap(MoveCell.down(board.curPos));
        }
        else if(keyEvent.getKeyCode()==KeyEvent.VK_UP||keyEvent.getKeyCode()==KeyEvent.VK_W){
            board.swap(MoveCell.up(board.curPos));
        }
        else if(keyEvent.getKeyCode()==KeyEvent.VK_LEFT||keyEvent.getKeyCode()==KeyEvent.VK_A){
            board.swap(MoveCell.left(board.curPos));
        }
        else if(keyEvent.getKeyCode()==KeyEvent.VK_RIGHT||keyEvent.getKeyCode()==KeyEvent.VK_D){
            board.swap(MoveCell.right(board.curPos));
        }
        board.revalidate();
        if(board.check())
            JOptionPane.showMessageDialog(this,"Congratulations you have completed the puzzle");


    }
}
