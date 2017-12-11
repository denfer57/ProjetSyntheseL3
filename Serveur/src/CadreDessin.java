
import java.awt.Graphics;
import java.awt.Toolkit;

import javax.swing.JFrame;

import java.awt.Dimension;

/**
 * destiné à recevoir des dessins réalisés en Active-Rendering
 *
 * paint() est désactivée
 *
 * pourrait être améliorée par l'utilisation d'un Canvas : Panel spécialisé pour le dessin
 * pourrait être améliorée par l'utilisation de coordonnées relatives plutôt que des coordonnées en pixels
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
