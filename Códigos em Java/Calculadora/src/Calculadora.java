import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Calculadora extends JFrame implements ActionListener{
    
    JLabel LCampo1,LCampo2, LResultado;
    JTextField tfCampo1, tfCampo2, tfResultado;
    JButton bSoma, bSub, bMult, bDiv,bLimpar;
    float num1, num2, resultado;
    
    public Calculadora(){
        setLayout(new FlowLayout());
        LCampo1 = new JLabel(" ");
        add(LCampo1);
        tfCampo1 = new JTextField(5);
        add(tfCampo1);
        LCampo2 = new JLabel(" ");
        add(LCampo2);
        tfCampo2 = new JTextField(5);
        add(tfCampo2);
        LResultado = new JLabel("Resultado: ");
        add(LResultado);
        tfResultado = new JTextField(" ", 5);
        tfResultado.setEditable(false);
        add(tfResultado);
        /////////////////////////////////////////////////////////
        tfCampo1.addActionListener(this);
        tfCampo2.addActionListener(this);
        /////////////////////////////////////////////////////////
        bSoma = new JButton("+");
        bSoma.addActionListener(this);
        add(bSoma);
        bSub = new JButton("-");
        bSub.addActionListener(this);
        add(bSub);
        bMult = new JButton("x");
        bMult.addActionListener(this);
        add(bMult);
        bDiv= new JButton("÷");
        bDiv.addActionListener(this);
        add(bDiv);
        bLimpar = new JButton("Limpar");
        bLimpar.addActionListener(this);
        add(bLimpar);
        /////////////////////////////////////////////////////////
        setSize(500, 150);
        setVisible(true);
        setTitle("Calculadora");
    }

    public static void main(String[] args) {
        Calculadora app = new Calculadora();
        app.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == tfCampo1){
            tfCampo2.requestFocus();
        }
        
        if((tfCampo1.getText().length() > 0) && (tfCampo2.getText().length() > 0) && (e.getSource() !=bLimpar)){
            JOptionPane.showMessageDialog(null, "Um cálculo!", "Parabéns", JOptionPane.PLAIN_MESSAGE);
        }

        if (e.getSource() == tfCampo1){
            if(tfCampo1.getText().length() == 0)
            JOptionPane.showMessageDialog(null, "Campo vazio!","Erro", JOptionPane.INFORMATION_MESSAGE);
        }else if (e.getSource() == tfCampo2){
            if(tfCampo2.getText().length() == 0)
            JOptionPane.showMessageDialog(null, "Campo vazio!","Erro", JOptionPane.INFORMATION_MESSAGE); 
        }       
    
        num1 = Float.parseFloat(tfCampo1.getText());
        num2 = Float.parseFloat(tfCampo2.getText());

        if (e.getSource() == bSoma) {          
            resultado = num1 + num2;
        } else if (e.getSource() == bSub) {
            resultado = num1 - num2;
        } else if (e.getSource() == bMult) {
            resultado = num1 * num2;
        } else if (e.getSource() == bDiv) {
            if (num2 == 0) {
                JOptionPane.showMessageDialog(null, "Divisão por zero!", "Erro", JOptionPane.ERROR_MESSAGE);
            } else {
                resultado = num1 / num2;                
            }
        } else if (e.getSource() == bLimpar) {
            tfCampo1.setText("");
            tfCampo2.setText("");
            tfResultado.setText("");            
        }
        tfResultado.setText(String.valueOf(resultado));
    }
}