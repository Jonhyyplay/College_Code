import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Aplicativo extends JFrame implements ActionListener{
    
    JLabel LNome,LEnd,LEst,LCid;
    JTextField tfNome, tfEnd;
    JButton bSalvar, bLimpar, bSair;
    JComboBox<String> cbEst, cbCid;
    
    public Aplicativo(){
        setLayout(new FlowLayout());
        LNome = new JLabel("Nome: ");
        add(LNome);
        tfNome = new JTextField(20);
        add(tfNome);
        LEnd = new JLabel("Sobrenome: ");
        add(LEnd);
        tfEnd = new JTextField(20);
        add(tfEnd);
        LEst = new JLabel("Estado");
        add(LEst);
        LCid = new JLabel("Cidade");
        add(LCid);
        /////////////////////////////////////////////////////////
        String [] estado = {" ", "MA","PA","PI"};
        cbEst = new JComboBox<String>(estado);
        add(cbEst);
        String [] cidade = {" ", "Itz", "Belém", "Parnaíba"};
        cbCid = new JComboBox<String>(cidade);
        add(cbCid);
        /////////////////////////////////////////////////////////
        tfNome.addActionListener(this);
        tfEnd.addActionListener(this);
        /////////////////////////////////////////////////////////
        bSalvar = new JButton("Salvar");
        bSalvar.addActionListener(this);
        add(bSalvar);
        bLimpar = new JButton("Limpar");
        bLimpar.addActionListener(this);
        add(bLimpar);
        bSair = new JButton("Sair");
        bSair.addActionListener(this);
        add(bSair);
        /////////////////////////////////////////////////////////
        setSize(1500, 150);
        setVisible(true);
        setTitle("Aula de POO1");
    }

    public static void main(String[] args) {
        Aplicativo app = new Aplicativo();
        app.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public void actionPerformed (ActionEvent e) {
        if (e.getSource() == tfNome){
            tfEnd.requestFocus();
        }

        if (e.getSource() == tfNome){
            if(tfNome.getText().length() == 0)
            JOptionPane.showMessageDialog(null, "Campo Nome vazio!","Erro", JOptionPane.ERROR_MESSAGE);
        }else if (e.getSource() == tfEnd){
            if(tfEnd.getText().length() == 0)
            JOptionPane.showMessageDialog(null, "Campo Nome vazio!","Erro", JOptionPane.ERROR_MESSAGE);  
        }

        if(e.getSource() == bSalvar){
            JOptionPane.showMessageDialog(null, "Salvo com Sucesso!","Ótimo", JOptionPane. INFORMATION_MESSAGE);
            tfNome.setText("");
            tfEnd.setText("");           
        }else if(e.getSource() == bSair){
            System.exit(0);
        }else if(e.getSource() == bLimpar){
            JOptionPane.showMessageDialog(null, "Informações limpadas com sucesso!","Limpo", JOptionPane.INFORMATION_MESSAGE);
            tfNome.setText("");
            tfEnd.setText("");
        }        
    }
}
