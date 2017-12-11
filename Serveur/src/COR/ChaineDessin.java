package COR;

public class ChaineDessin {

	private static DessinCOR chaine;

	public static DessinCOR getChaine() {
		if (chaine == null)
		{
			//DecodeDessinCOR decodeDessinGroupe = new DecodeDessinGroupeCOR(null);
			//DecodeDessinCOR decodeDessinPolygone = new DecodeDessinPolygoneCOR(decodeDessinGroupe);
			DessinCOR dechiffreDessinCercle = new RealiseDessinCercleCOR(null);
			DessinCOR dechiffreDessinSegment = new RealiseDessinSegmentCOR(dechiffreDessinCercle);
			chaine = dechiffreDessinSegment;
		}
		return chaine;
	}

}