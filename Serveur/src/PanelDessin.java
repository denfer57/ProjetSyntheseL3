import java.awt.Graphics;

import javax.swing.JComponent;

import COR.ChaineDessin;

public class PanelDessin extends JComponent{

	/**
	 *
	 */
	private static final long serialVersionUID = 1L;

	private String _nomDessin;

	public PanelDessin(String nomDessin) {
		// TODO Auto-generated constructor stub
		super();
		_nomDessin = nomDessin;
	}

	@Override
	protected void paintComponent(Graphics g)
	{
		super.paintComponent(g);
		//si l'on a rien a dessiner, on affiche l'ecran d'erreur
		if (!ChaineDessin.getChaine().dessiner(_nomDessin, g))
		{
			g.drawString("Erreur lors de la création du dessin !", (getWidth() / 2), getHeight() / 2);
		}
	}
}
