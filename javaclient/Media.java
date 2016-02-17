/*
 * Window
 */
package javaclient;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
/** 
 * Media is a window who inherits JFrame and ActionListener
 * 
 */
public class Media extends JFrame 
                   implements ActionListener       {
	private static final long serialVersionUID = 1L;
	JPanel p;
	JButton button1=null;
	JButton button2=null;
	JButton button3=null;
    JTextArea text=null;
    JTextField textF=null;
    JLabel label = null;
	JMenuBar menuBar=null;
	JMenu menu=null;
	JMenuItem menuItem1=null;
	JMenuItem menuItem2=null;
	JMenuItem menuItem3=null;
	JToolBar toolBar=null;
	JButton tbutton1=null;
	JButton tbutton2=null;
	JButton tbutton3=null;
	public Client client;
	
	/*public static void main(String argv[]){
		new Media();
	}*/
	
	/**
	 * constructor
	 * @param client
	 */
	public Media(Client client){
		this.client=client;
		this.setTitle("Meutimedia");
		this.setSize(1000, 500);
		this.setLayout(new BorderLayout());
		
		p=new JPanel();
		button1=new JButton("search");
		tbutton1=new JButton("search");
		p.add(button1);
        button2=new JButton("play");
        tbutton2=new JButton("play");
        p.add(button2);
        button3=new JButton("Exit");
        tbutton3=new JButton("Exit");
        p.add(button3);
        add(p,BorderLayout.SOUTH);
        
        label=new JLabel("Tape the name");
		text=new JTextArea(50,100);
		textF=new JTextField(50);
		text.setEditable(false);
		text.setText("\n Files include:\n  famille: photo1, photo2, video1;\n  travail: vedio1,film1,film2 \n");
		JScrollPane scrollPane = new JScrollPane(text); 
		setPreferredSize(new Dimension(450, 300));
		add(scrollPane,BorderLayout.CENTER);
		 
		
		menuBar=new JMenuBar();
		menu = new JMenu("Menu");
		menuBar.add(menu);
		menuItem1 = new JMenuItem("search",
                KeyEvent.VK_T);
		menu.add(menuItem1);
		menuItem2 = new JMenuItem("play",
                KeyEvent.VK_T);
		menu.add(menuItem2);
		menuItem3 = new JMenuItem("exit",
                KeyEvent.VK_T);
		menu.add(menuItem3);
		this.setJMenuBar(menuBar);
		
		toolBar= new JToolBar("Toolbar");
		toolBar.add(tbutton1);
		toolBar.add(tbutton2);
		toolBar.add(tbutton3);
		toolBar.add(label);
		toolBar.add(textF);
		add(toolBar, BorderLayout.NORTH);
		
		//textF.addActionListener(this);
		button1.addActionListener(this);
		button2.addActionListener(this);
		button3.addActionListener(this);
		tbutton1.addActionListener(this);
		tbutton2.addActionListener(this);
		tbutton3.addActionListener(this);
		menuItem1.addActionListener(this);
		menuItem2.addActionListener(this);
		menuItem3.addActionListener(this);
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Media");
		pack();
		setVisible(true);
	}
	/**
	 * Actions to be preformed  
	 */
	public void actionPerformed(ActionEvent e) {
		String line=System.getProperty("line.separator");
		String message;
		String response;
		if (e.getSource() == button1 || e.getSource() == tbutton1 || e.getSource() == menuItem1)
		{
			message="search"+"\t"+textF.getText();
			response=client.send(message);
			text.append(response+line);
			
		}
		else if(e.getSource() == button2 || e.getSource() == tbutton2 || e.getSource() == menuItem2)
		{
			message="play"+"\t"+textF.getText();
			response=client.send(message);
			text.append(response+line);
		}
		else if(e.getSource()==button3 || e.getSource() == tbutton3 || e.getSource() == menuItem3)
		     System.exit(0);
		/*else if(e.getSource()==textF)
		{
			s= textF.getText();
            text.append(text + "\n");
		}*/
    }
	

	
}




