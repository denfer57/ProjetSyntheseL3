package COR;

public class ChaineDessin {

	private static DessinCOR chaine;

	public static DessinCOR getChaine() {
		if (chaine == null)
		{
			//on passe par toutes les méthodes pour dessiner en fonction de ce que c'est
			DessinCOR decodeDessinGroupe = new RealiseDessinGroupeCOR(null);
			DessinCOR dechiffreDessinCercle = new RealiseDessinCercleCOR(decodeDessinGroupe);
			DessinCOR dechiffreDessinSegment = new RealiseDessinSegmentCOR(dechiffreDessinCercle);
			DessinCOR decodeDessinPolygone = new RealiseDessinPolygoneCOR(dechiffreDessinSegment);
			chaine = decodeDessinPolygone;
		}
		return chaine;
	}

}