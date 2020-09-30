import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import javax.swing.filechooser.FileSystemView;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class Launcher extends JFrame implements ActionListener {

    private void design(){
        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        select=new JButton("Select a file");
        select.addActionListener(this);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
                layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                .addGroup(layout.createSequentialGroup()
                            .addGap(200)
                            .addComponent(select)
                            .addGap(200)
                )

        );
        layout.setVerticalGroup(
                layout.createSequentialGroup()
                        .addGap(50)
                        .addComponent(select)
                        .addGap(50)
        );

        setTitle("Launcher");
        pack();
        setLocationRelativeTo(null);
        setVisible(true);

    }
    public Launcher(){
        design();
    }
    public static void main(String args[]){
        new Launcher();
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        JFileChooser chooser=new JFileChooser(FileSystemView.getFileSystemView());
        FileNameExtensionFilter filter= new FileNameExtensionFilter("*.jpg,*.png","jpg","png");
        chooser.setDialogTitle("Select an image");
        chooser.setFileFilter(filter);

        int r=chooser.showDialog(null,"Select");
        if(r==JFileChooser.APPROVE_OPTION){
            try {
                String path=chooser.getSelectedFile().getAbsolutePath();
                File imageFile=new File(path);
                img= ImageIO.read(imageFile);
                new Puzzle(ImageResizer.resize(img,800,800));

            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    JButton select;
    BufferedImage img;
}





