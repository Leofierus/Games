import java.awt.Component;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import javax.swing.ButtonGroup;
import javax.swing.GroupLayout;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JRadioButton;
import javax.swing.GroupLayout.Alignment;
import javax.swing.filechooser.FileNameExtensionFilter;
import javax.swing.filechooser.FileSystemView;

public class Launcher extends JFrame implements ActionListener {
    JButton select;
    JRadioButton easy;
    JRadioButton medium;
    JRadioButton hard;
    ButtonGroup buttonGroup;
    BufferedImage img;

    private void design() {
        this.setDefaultCloseOperation(3);
        this.select = new JButton("Select a file");
        this.easy = new JRadioButton("Easy");
        this.medium = new JRadioButton("Medium");
        this.hard = new JRadioButton("Hard");
        this.select.addActionListener(this);
        this.buttonGroup = new ButtonGroup();
        this.buttonGroup.add(this.easy);
        this.buttonGroup.add(this.medium);
        this.buttonGroup.add(this.hard);
        this.easy.setSelected(true);
        GroupLayout layout = new GroupLayout(this.getContentPane());
        this.getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
                layout.createParallelGroup(Alignment.LEADING)
                        .addGroup(layout.createSequentialGroup()
                                .addGap(200).addComponent(this.select)
                                .addGap(200)).addGroup(layout.createSequentialGroup()
                        .addGap(160).addComponent(this.easy)
                        .addContainerGap()
                        .addComponent(this.medium)
                        .addContainerGap()
                        .addComponent(this.hard)
                )
        );
        layout.setVerticalGroup(
                layout.createSequentialGroup()
                        .addGap(50)
                        .addComponent(this.select)
                        .addGap(20)
                        .addGroup(
                                layout.createParallelGroup(Alignment.BASELINE)
                                        .addComponent(this.easy)
                                        .addComponent(this.medium)
                                        .addComponent(this.hard)
                                        .addGap(50)
                        )
        );
        this.setTitle("Launcher");
        this.pack();
        this.setLocationRelativeTo((Component) null);
        this.setVisible(true);
    }

    public Launcher() {
        this.design();
    }

    public static void main(String[] args) {
        new Launcher();
    }

    public void actionPerformed(ActionEvent actionEvent) {
        JFileChooser chooser = new JFileChooser(FileSystemView.getFileSystemView());
        FileNameExtensionFilter filter = new FileNameExtensionFilter("*.jpg,*.png", new String[]{"jpg", "png"});
        chooser.setDialogTitle("Select an image");
        chooser.setFileFilter(filter);
        int r = chooser.showDialog((Component) null, "Select");
        if (r == 0) {
            try {
                String path = chooser.getSelectedFile().getAbsolutePath();
                File imageFile = new File(path);
                this.img = ImageIO.read(imageFile);
                int level = 3;
                if (this.easy.isSelected()) {
                    level = 3;
                } else if (this.medium.isSelected()) {
                    level = 4;
                } else if (this.hard.isSelected()) {
                    level = 5;
                }

                new Puzzle(ImageResizer.resize(this.img, 800, 800), level);
            } catch (IOException var8) {
                var8.printStackTrace();
            }
        }

    }
}





