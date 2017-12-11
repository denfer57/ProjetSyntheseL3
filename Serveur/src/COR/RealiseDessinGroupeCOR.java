package COR;

import java.awt.Graphics;

public class RealiseDessinGroupeCOR extends DessinCOR {

	protected RealiseDessinGroupeCOR(DessinCOR suivant) {
		super(suivant);
		// TODO Auto-generated constructor stub
	}

	@Override
	protected boolean goDessiner(String dessin, Graphics g) {
		// TODO Auto-generated method stub
		try
		{
			String[] tab = dessin.trim().split("\n");
			if (tab.length > 2)//au moins 1 forme dans le groupe
			{
				for (String forme : tab){
					if (forme.startsWith("*")){
						forme = forme.substring(1, forme.length());
						ChaineDessin.getChaine().dessiner(forme, g);
					}
				}

				return true;
			}
		}
		catch (Exception e) { }

		return false;
	}

}
