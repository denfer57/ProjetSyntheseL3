package COR;

public class ChaineDessin {

	private static DessinCOR chaine;

	public static DessinCOR getChaine() {
		if (chaine == null)
		{
			DessinCOR dechiffreDessinCercle = new RealiseDessinCercleCOR(null);
			DessinCOR dechiffreDessinSegment = new RealiseDessinSegmentCOR(dechiffreDessinCercle);
			DessinCOR decodeDessinPolygone = new RealiseDessinPolygoneCOR(dechiffreDessinSegment);
			chaine = decodeDessinPolygone;
		}
		return chaine;
	}

}