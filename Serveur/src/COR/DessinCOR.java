package COR;

import java.awt.Graphics;

public abstract class DessinCOR implements InterfaceDessin
{
	protected DessinCOR _suivant;

	protected DessinCOR(DessinCOR suivant)
	{
		super();
		_suivant = suivant;
	}

	public boolean dessiner(String dessin, Graphics g)
	{
		if (goDessiner(dessin, g))
			return true;

		if (_suivant == null)
			return false;
		else
			return _suivant.dessiner(dessin, g);
	}

	protected abstract boolean goDessiner(String dessin, Graphics g);
}