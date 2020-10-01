import java.awt.Color;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.image.BufferedImage;
import javax.swing.GroupLayout;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.GroupLayout.Alignment;

public class Puzzle extends JFrame implements KeyListener {
    Board board;
    JPanel sample;
    JLabel miniImage;

    Puzzle(BufferedImage img, int level) {
        this.setDefaultCloseOperation(2);
        this.addKeyListener(this);
        GroupLayout layout = new GroupLayout(this.getContentPane());
        this.getContentPane().setLayout(layout);
        this.sample = new JPanel();
        this.sample.setSize(800, 300);
        this.sample.setBackground(Color.BLACK);
        this.miniImage = new JLabel();
        this.miniImage.setSize(300, 300);
        this.miniImage.setIcon(new ImageIcon(img.getScaledInstance(300, 300, 8)));
        this.sample.add(this.miniImage, "South");
        this.setSize(new Dimension(800, 800));
        this.board = new Board(img, level);
        this.board.add();
        this.board.shuffle();
        layout.setHorizontalGroup(layout.createSequentialGroup().addComponent(this.board).addComponent(this.sample));
        layout.setVerticalGroup(layout.createParallelGroup(Alignment.LEADING).addComponent(this.board).addComponent(this.sample));
        this.pack();
        this.setLocationRelativeTo((Component)null);
        this.setVisible(true);
    }

    public void keyTyped(KeyEvent keyEvent) {
    }

    public void keyPressed(KeyEvent keyEvent) {
    }

    public void keyReleased(KeyEvent keyEvent) {
        if (keyEvent.getKeyCode() != 83 && keyEvent.getKeyCode() != 40) {
            if (keyEvent.getKeyCode() != 38 && keyEvent.getKeyCode() != 87) {
                if (keyEvent.getKeyCode() != 37 && keyEvent.getKeyCode() != 65) {
                    if (keyEvent.getKeyCode() == 39 || keyEvent.getKeyCode() == 68) {
                        this.board.swap(MoveCell.right(this.board.curPos, this.board.level));
                    }
                } else {
                    this.board.swap(MoveCell.left(this.board.curPos, this.board.level));
                }
            } else {
                this.board.swap(MoveCell.up(this.board.curPos, this.board.level));
            }
        } else {
            this.board.swap(MoveCell.down(this.board.curPos, this.board.level));
        }

        this.board.revalidate();
        if (this.board.check()) {
            JOptionPane.showMessageDialog(this, "Congratulations you have completed the puzzle");
        }

    }
}
