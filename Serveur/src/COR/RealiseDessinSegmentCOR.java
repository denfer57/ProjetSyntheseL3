package COR;

import java.awt.Graphics;

public class RealiseDessinSegmentCOR  extends DessinCOR
{
	public RealiseDessinSegmentCOR(DessinCOR suivant)
	{
		super(suivant);
	}

	@Override
	protected boolean goDessiner(String dessin, Graphics g)
	{
		try
		{
			String[] tab = dessin.trim().split(" / ");
			if (tab[0].equals("Segment"))
			{
				double[] pointA = DechiffreChaine.dechiffrePoint(tab[2]);
				double[] pointB = DechiffreChaine.dechiffrePoint(tab[3]);

				g.setColor(DechiffreChaine.dechiffreCouleur(tab[1]));
				g.drawLine((int)pointA[0],(int) pointA[1], (int)pointB[0], (int)pointB[1]);

				return true;
			}
		}
		catch (Exception e) { }

		return false;
	}
}
