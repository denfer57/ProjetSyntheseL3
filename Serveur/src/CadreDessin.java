
import java.awt.Graphics;
import java.awt.Toolkit;

import javax.swing.JFrame;

import java.awt.Dimension;

/**
 * destin� � recevoir des dessins r�alis�s en Active-Rendering
 *
 * paint() est d�sactiv�e
 *
 * pourrait �tre am�lior�e par l'utilisation d'un Canvas : Panel sp�cialis� pour le dessin
 * pourrait �tre am�lior�e par l'utilisation de coordonn�es relatives plut�t que des coordonn�es en pixels
 * */
public class CadreDessin extends JFrame
{
/**
	 *
	 */
	private static final long serialVersionUID = 1L;

public CadreDessin(String titre, String nomDessin) throws InterruptedException
{
	super();
	creerCadre(titre);

	PanelDessin panel = new PanelDessin(nomDessin);
	this.add(panel);
}

private void creerCadre(String titre) {
	setTitle(titre);
	setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
	setMinimumSize(new Dimension(500, 500));
	setVisible(true);
}

}
