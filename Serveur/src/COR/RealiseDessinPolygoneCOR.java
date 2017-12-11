package COR;

import java.awt.Graphics;

public class RealiseDessinPolygoneCOR extends DessinCOR {

	protected RealiseDessinPolygoneCOR(DessinCOR suivant) {
		super(suivant);
		// TODO Auto-generated constructor stub
	}

	@Override
	protected boolean goDessiner(String dessin, Graphics g) {
		// TODO Auto-generated method stub
		try
		{
			String[] tab = dessin.trim().split(" / ");
			if (tab[0].equals("Polygone"))
			{
				int nbPoints = tab.length-2;
				int[] x = new int[nbPoints];
				int[] y = new int[nbPoints];
				for(int i = 2 ; i < tab.length; i++)
				{
					double[] point = DechiffreChaine.dechiffrePoint(tab[i]);
					x[i-2] = (int) point[0];
					y[i-2] = (int) point[1];
				}

				g.setColor(DechiffreChaine.dechiffreCouleur(tab[1]));

				g.fillPolygon(x, y, nbPoints);

				return true;
			}
		}
		catch (Exception e) { }

		return false;
	}

}
