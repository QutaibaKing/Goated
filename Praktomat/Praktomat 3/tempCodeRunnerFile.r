import math

def spannungen_berechnen(sigma_x, sigma_y, tau_xy, phi_deg):
    phi_rad = math.radians(phi_deg)
    
    sigma_xi = 0.5 * (sigma_x + sigma_y) + 0.5 * (sigma_x - sigma_y) * math.cos(2 * phi_rad) + tau_xy * math.sin(2 * phi_rad)
    sigma_eta = 0.5 * (sigma_x + sigma_y) - 0.5 * (sigma_x - sigma_y) * math.cos(2 * phi_rad) - tau_xy * math.sin(2 * phi_rad)
    tau_xi_eta = -0.5 * (sigma_x - sigma_y) * math.sin(2 * phi_rad) + tau_xy * math.cos(2 * phi_rad)

    return sigma_xi, sigma_eta, tau_xi_eta


# Eingaben durch den Benutzer
sigma_x = float(input("σx eingeben: "))
sigma_y = float(input("σy eingeben: "))
tau_xy = float(input("τxy eingeben: "))
phi_deg = float(input("Winkel φ in Grad eingeben: "))

# Berechnung
ergebnis = spannungen_berechnen(sigma_x, sigma_y, tau_xy, phi_deg)

# Ausgabe
print(f"σξ = {ergebnis[0]:.3f}")
print(f"ση = {ergebnis[1]:.3f}")
print(f"τηξ = τξη = {ergebnis[2]:.3f}")