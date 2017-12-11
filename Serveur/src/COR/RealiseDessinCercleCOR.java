package COR;

import java.awt.Graphics;

public class RealiseDessinCercleCOR extends DessinCOR
{
	public RealiseDessinCercleCOR(DessinCOR suivant)
	{
		super(suivant);
	}

	@Override
	protected boolean goDessiner(String dessin, Graphics g)
	{
		try
		{
			String[] tab = dessin.trim().split(" / ");
			if (tab[0].equals("Cercle"))
			{
				double[] centre = DechiffreChaine.dechiffrePoint(tab[2]);
				double rayon = Double.parseDouble(tab[3]);

				g.setColor(DechiffreChaine.dechiffreCouleur(tab[1]));
				g.fillOval((int)(centre[0] - rayon), (int)(centre[0] - rayon), (int)(2*rayon), (int)(2*rayon));

				return true;
			}
		}
		catch (Exception e) { }

		return false;
	}
}
